#include "Renderer.h"


Renderer::Renderer()
{
	ResourceFactory * loader = ResourceFactory::GetInstance();
	m_staticShader = new StaticShader();
	m_terrainShader = new TerrainShader();
	loader->LoadShader("res/Shaders/staticShader.vert", "res/Shaders/staticShader.frag", &m_staticShader);
	loader->LoadShader("res/Shaders/terrainShader.vert", "res/Shaders/terrainShader.frag", &m_terrainShader);
}

Renderer::Renderer(const Renderer & other)
{

}

Renderer::~Renderer()
{

}

void Renderer::Init()
{
	CreateProjectionMatrix();
	m_staticShader->Start();
	((StaticShader*)m_staticShader)->LoadProjectionMatrix(m_projectionMatrix);
	m_staticShader->Stop();
	m_terrainShader->Start();
	((TerrainShader*)m_terrainShader)->LoadProjectionMatrix(m_projectionMatrix);
	m_terrainShader->Stop();
}

void Renderer::PrepareRender()
{
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glClearColor(0.392f, 0.584f, 0.929f, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void Renderer::RenderModel(ModelOBJ * model)
{
	m_staticShader->Start();
	glBindVertexArray(model->GetVAOID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	//Transformation matrix

	glEnable(GL_TEXTURE_2D);
	glm::mat4x4 transformationMatrix = MathHelper::CreateTransformationMatrix(glm::vec3(0, -5, -15), 0, 90, 0, 1);
	
	StaticShader * shader = (StaticShader*)m_staticShader;
	((StaticShader*)m_staticShader)->LoadTransformationMatrix(transformationMatrix);

	glActiveTexture(GL_TEXTURE0);
	model->GetTexture()->BindTexture();
	glDrawElements(GL_TRIANGLES, model->GetVertexCount(), GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glBindVertexArray(0);
}

void Renderer::CreateProjectionMatrix()
{
	int width = 0, height = 0;
	GlutWindow::GetInstance()->GetWindowSize(width, height);
	float aspectRatio = (float)width / (float)height;
	m_projectionMatrix = glm::perspective(FOV, aspectRatio, NEAR_PLANE, FAR_PLANE);
}

void Renderer::SetView(Camera * camera)
{
	m_staticShader->Start();
	((StaticShader*)m_staticShader)->LoadViewMatrix(camera);
	m_staticShader->Stop();
	m_terrainShader->Start();
	((TerrainShader*)m_terrainShader)->LoadViewMatrix(camera);
	m_terrainShader->Stop();
}

void Renderer::RenderTerrain(Terrain * terrain)
{
	m_staticShader->Start();
	glBindVertexArray(terrain->GetVAOID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	//Transformation matrix

	glEnable(GL_TEXTURE_2D);
	glm::mat4x4 transformationMatrix = MathHelper::CreateTransformationMatrix(glm::vec3(0, -5, -15), 0, 90, 0, terrain->GetScale().x);

	TerrainShader * shader = (TerrainShader*)m_terrainShader;
	((TerrainShader*)m_terrainShader)->LoadTransformationMatrix(transformationMatrix);

	glActiveTexture(GL_TEXTURE0);
	//model->GetTexture()->BindTexture();
	glDrawElements(GL_TRIANGLES, terrain->GetVertexCount(), GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glBindVertexArray(0);
}
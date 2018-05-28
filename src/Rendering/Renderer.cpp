#include "Renderer.h"


Renderer::Renderer()
{
	ResourceFactory * loader = ResourceFactory::GetInstance();
	m_staticShader = new StaticShader();
	m_terrainShader = new TerrainShader();
	m_animatedShader = new AnimatedShader();
	m_skyboxShader = new SkyboxShader();
	loader->LoadShader("res/Shaders/staticShader.vert", "res/Shaders/staticShader.frag", &m_staticShader);
	loader->LoadShader("res/Shaders/terrainShader.vert", "res/Shaders/terrainShader.frag", &m_terrainShader);
	loader->LoadShader("res/Shaders/animatedShader.vert", "res/Shaders/animatedShader.frag", &m_animatedShader);
	loader->LoadShader("res/shaders/skyboxShader.vert", "res/shaders/skyboxShader.frag", &m_skyboxShader);
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
	m_animatedShader->Start();
	((AnimatedShader*)m_animatedShader)->LoadProjectionMatrix(m_projectionMatrix);
	m_animatedShader->Stop();
	m_skyboxShader->Start();
	((SkyboxShader*)m_skyboxShader)->LoadProjectionMatrix(m_projectionMatrix);
	m_skyboxShader->Stop();
}

void Renderer::PrepareRender()
{
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE); // Debugging
	glClearColor(0.392f, 0.584f, 0.929f, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void Renderer::RenderGameObject(GameObject * obj)
{
	m_staticShader->Start();
	ModelBase * model = obj->GetModel();
	glBindVertexArray(model->GetVAOID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	//Transformation matrix

	glEnable(GL_TEXTURE_2D);
	glm::mat4x4 transformationMatrix = obj->GetTransformationMatrix();//MathHelper::CreateTransformationMatrix(obj->GetPosition(), obj->GetRotation(), obj->GetScale());

	StaticShader * shader = (StaticShader*)m_staticShader;
	((StaticShader*)m_staticShader)->LoadTransformationMatrix(transformationMatrix);

	glActiveTexture(GL_TEXTURE0);
	model->GetTexture()->BindTexture();
	glDrawElements(GL_TRIANGLES, model->GetVertexCount(), GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glBindVertexArray(0);
	m_staticShader->Stop();
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
	m_animatedShader->Start();
	((AnimatedShader*)m_animatedShader)->LoadViewMatrix(camera);
	m_animatedShader->Stop();
	m_skyboxShader->Start();
	((SkyboxShader*)m_skyboxShader)->LoadViewMatrix(camera);
	m_skyboxShader->Stop();
}

void Renderer::RenderTerrain(Terrain * terrain)
{
	m_terrainShader->Start();
	glBindVertexArray(terrain->GetVAOID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);
	((TerrainShader*)m_terrainShader)->LoadTextures();
	((TerrainShader*)m_terrainShader)->LoadLight(glm::vec3(1.0f, 1.0f, 1.0f));

	glEnable(GL_TEXTURE_2D);
	glm::mat4x4 transformationMatrix = MathHelper::CreateTransformationMatrix(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), terrain->GetScale());

	TerrainShader * shader = (TerrainShader*)m_terrainShader;
	((TerrainShader*)m_terrainShader)->LoadTransformationMatrix(transformationMatrix);

	glActiveTexture(GL_TEXTURE0);
	TerrainTextures * textures = terrain->GetTextures();
	textures->GetBaseTexture()->BindTexture();
	glActiveTexture(GL_TEXTURE1);
	textures->GetTexture(0)->BindTexture();
	glActiveTexture(GL_TEXTURE2);
	textures->GetTexture(1)->BindTexture();
	glActiveTexture(GL_TEXTURE3);
	textures->GetTexture(2)->BindTexture();
	glActiveTexture(GL_TEXTURE4);
	textures->GetDetailMap()->BindTexture();
	glDrawElements(GL_TRIANGLES, terrain->GetVertexCount(), GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(3);
	glBindVertexArray(0);
	m_terrainShader->Stop();
}

void Renderer::RenderSkybox(Skybox * skybox)
{
	m_skyboxShader->Start();
	glBindVertexArray(skybox->GetVAOID());
	glEnableVertexAttribArray(0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, skybox->GetTextureID());
	glDrawArrays(GL_TRIANGLES, 0, skybox->GetVertexCount());
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
	m_skyboxShader->Stop();
}
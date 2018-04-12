#include "Renderer.h"


Renderer::Renderer()
{
	m_shader = nullptr;
}

Renderer::Renderer(StaticShader * shader)
{
	m_shader = shader;
	
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
	m_shader->Start();
	m_shader->LoadProjectionMatrix(m_projectionMatrix);
	m_shader->Stop();
}

void Renderer::PrepareRender()
{
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glClearColor(0.392f, 0.584f, 0.929f, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::StartShader()
{
	m_shader->Start();
}

void Renderer::StopShader()
{
	m_shader->Stop();
}

void Renderer::RenderModel(ModelOBJ * model)
{
	glBindVertexArray(model->GetVAOID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	//Transformation matrix

	glEnable(GL_TEXTURE_2D);
	glm::mat4x4 transformationMatrix = MathHelper::CreateTransformationMatrix(glm::vec3(0, -5, -15), 0, 90, 0, 1);
	m_shader->LoadTransformationMatrix(transformationMatrix);

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
	m_shader->LoadViewMatrix(camera);
}

void Renderer::RenderTerrain(Terrain * terrain)
{
	glm::mat4x4 transformationMatrix = MathHelper::CreateTransformationMatrix(glm::vec3(0, -5, -15), 0, 90, 0, 1);
	m_shader->LoadTransformationMatrix(transformationMatrix);

	glBindVertexArray(terrain->GetVAOID());
	glDrawArrays(GL_TRIANGLE_STRIP, 0, terrain->GetSize());
}
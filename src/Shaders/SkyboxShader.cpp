#include "SkyboxShader.h"

SkyboxShader::SkyboxShader()
{

}

SkyboxShader::SkyboxShader(const SkyboxShader & other)
{

}

SkyboxShader::~SkyboxShader()
{

}

void SkyboxShader::BindAttributes()
{
	BindAttrib(0, "position");
}

void SkyboxShader::GetAllUniforms()
{
	m_location_projectionMatrix = GetUniform("projectionMatrix");
	m_location_viewMatrix = GetUniform("viewMatrix");
}

void SkyboxShader::LoadProjectionMatrix(glm::mat4x4 projectionMatrix)
{
	LoadMatrix4(m_location_projectionMatrix, projectionMatrix);
}

void SkyboxShader::LoadViewMatrix(Camera * cam)
{
	glm::mat4x4 viewMatrix = MathHelper::CreateViewMatrix(cam);
	viewMatrix[3][0] = 0;
	viewMatrix[3][1] = 0;
	viewMatrix[3][2] = 0;
	LoadMatrix4(m_location_viewMatrix, viewMatrix);
}
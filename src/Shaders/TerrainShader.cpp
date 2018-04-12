#include "TerrainShader.h"

TerrainShader::TerrainShader()
{

}

TerrainShader::TerrainShader(const TerrainShader & other)
{

}

TerrainShader::~TerrainShader()
{

}

void TerrainShader::BindAttributes()
{
	BindAttrib(0, "position");
	BindAttrib(1, "textureCoords");
	BindAttrib(2, "normal");
}

void TerrainShader::GetAllUniforms()
{
	m_location_projectionMatrix = GetUniform("projectionMatrix");
	m_location_transformationMatrix = GetUniform("transformationMatrix");
	m_location_viewMatrix = GetUniform("viewMatrix");
}

void TerrainShader::LoadProjectionMatrix(glm::mat4x4 projectionMatrix)
{
	LoadMatrix4(m_location_projectionMatrix, projectionMatrix);
}

void TerrainShader::LoadTransformationMatrix(glm::mat4x4 transformationMatrix)
{
	LoadMatrix4(m_location_transformationMatrix, transformationMatrix);
}

void TerrainShader::LoadViewMatrix(Camera * camera)
{
	glm::mat4x4 viewMatrix = MathHelper::CreateViewMatrix(camera);
	LoadMatrix4(m_location_viewMatrix, viewMatrix);
}
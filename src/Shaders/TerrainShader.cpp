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
	BindAttrib(3, "detailTexCoords");
}

void TerrainShader::GetAllUniforms()
{
	m_location_projectionMatrix = GetUniform("projectionMatrix");
	m_location_transformationMatrix = GetUniform("transformationMatrix");
	m_location_viewMatrix = GetUniform("viewMatrix");
	m_location_baseTexture = GetUniform("baseTexture");
	m_location_rTexture = GetUniform("rTexture");
	m_location_gTexture = GetUniform("gTexture");
	m_location_bTexture = GetUniform("bTexture");
	m_location_detailMapTexture = GetUniform("detailMapTexture");
	m_location_lightColor = GetUniform("lightColor");
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

void TerrainShader::LoadTextures()
{
	LoadInt(m_location_baseTexture, 0);
	LoadInt(m_location_rTexture, 1);
	LoadInt(m_location_gTexture, 2);
	LoadInt(m_location_bTexture, 3);
	LoadInt(m_location_detailMapTexture, 4);
}

void TerrainShader::LoadLight(glm::vec3 light)
{
	LoadVec3(m_location_lightColor, light);
}
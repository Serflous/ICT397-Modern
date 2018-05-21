#include "AnimatedShader.h"

AnimatedShader::AnimatedShader()
{

}

AnimatedShader::AnimatedShader(const AnimatedShader & other)
{

}

AnimatedShader::~AnimatedShader()
{

}

void AnimatedShader::BindAttributes()
{
	BindAttrib(0, "position");
	BindAttrib(1, "textureCoords");
	BindAttrib(2, "normal");
	BindAttrib(3, "boneIndicies");
	BindAttrib(4, "weights");
}

void AnimatedShader::GetAllUniforms()
{
	m_location_boneTransforms = GetUniform("boneTransforms");
	m_location_projectionMatrix = GetUniform("projectionMatrix");
	m_location_viewMatrix = GetUniform("viewMatrix");
	m_location_transformationMatrix = GetUniform("transformationMatrix");
}

void AnimatedShader::LoadProjectionMatrix(glm::mat4x4 matrix)
{
	LoadMatrix4(m_location_projectionMatrix, matrix);
}

void AnimatedShader::LoadTransformationMatrix(glm::mat4x4 matrix)
{
	LoadMatrix4(m_location_transformationMatrix, matrix);
}

void AnimatedShader::LoadViewMatrix(Camera * cam)
{
	glm::mat4x4 viewMatrix = MathHelper::CreateViewMatrix(cam);
	LoadMatrix4(m_location_viewMatrix, viewMatrix);
}
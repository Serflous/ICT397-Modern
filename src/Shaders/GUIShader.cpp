#include "GUIShader.h"

GUIShader::GUIShader()
{

}

GUIShader::GUIShader(const GUIShader & other)
{

}

GUIShader::~GUIShader()
{

}

void GUIShader::BindAttributes()
{
	BindAttrib(0, "position");
}

void GUIShader::GetAllUniforms()
{
	m_location_transformationMatrix = GetUniform("transformationMatrix");
}

void GUIShader::LoadTransformationMatrix(glm::mat4x4 transformationMatrix)
{
	LoadMatrix4(m_location_transformationMatrix, transformationMatrix);
}
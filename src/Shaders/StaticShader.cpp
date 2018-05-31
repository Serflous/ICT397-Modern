#include "StaticShader.h"

StaticShader::StaticShader()
{

}

StaticShader::StaticShader(const StaticShader & other)
{

}

StaticShader::~StaticShader()
{

}

void StaticShader::BindAttributes()
{
	BindAttrib(0, "position");
	BindAttrib(1, "textureCoords");
	BindAttrib(2, "normal");
}

void StaticShader::GetAllUniforms()
{
	m_location_projectionMatrix = GetUniform("projectionMatrix");
	m_location_transformationMatrix = GetUniform("transformationMatrix");
	m_location_viewMatrix = GetUniform("viewMatrix");
	m_location_entityId = GetUniform("entityId");
	m_location_useId = GetUniform("userId");
	
}

void StaticShader::LoadProjectionMatrix(glm::mat4x4 projectionMatrix)
{
	//std::cout << "Projection Matrix;" << std::endl;
	//for (int i = 0; i < 4; i++)
		//std::cout << projectionMatrix[i][0] << "\t" << projectionMatrix[i][1] << "\t" << projectionMatrix[i][2] << "\t" << projectionMatrix[i][3] << std::endl;
	LoadMatrix4(m_location_projectionMatrix, projectionMatrix);
}

void StaticShader::LoadTransformationMatrix(glm::mat4x4 transformationMatrix)
{
	//std::cout << "Transformation Matrix;" << std::endl;
	//for (int i = 0; i < 4; i++)
		//std::cout << transformationMatrix[i][0] << "\t" << transformationMatrix[i][1] << "\t" << transformationMatrix[i][2] << "\t" << transformationMatrix[i][3] << std::endl;
	LoadMatrix4(m_location_transformationMatrix, transformationMatrix);
}

void StaticShader::LoadViewMatrix(Camera * cam)
{
	glm::mat4x4 viewMatrix = MathHelper::CreateViewMatrix(cam);
	//std::cout << "View Matrix;" << std::endl;
	//for (int i = 0; i < 4; i++)
		//std::cout << viewMatrix[i][0] << "\t" << viewMatrix[i][1] << "\t" << viewMatrix[i][2] << "\t" << viewMatrix[i][3] << std::endl;
	LoadMatrix4(m_location_viewMatrix, viewMatrix);
}

void StaticShader::LoadEntityId(int id)
{
	LoadUInt(m_location_entityId, id);
}

void StaticShader::LoadUseID(bool useId)
{
	LoadBoolean(m_location_useId, useId);
}
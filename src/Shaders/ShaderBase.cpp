#include "ShaderBase.h"

ShaderBase::ShaderBase()
{

}

ShaderBase::ShaderBase(const ShaderBase & other)
{

}

ShaderBase::~ShaderBase()
{

}

void ShaderBase::Start()
{
	glUseProgram(m_programId);
}

void ShaderBase::Stop()
{
	glUseProgram(0);
}

void ShaderBase::BindAttrib(int attrib, const char * name)
{
	glBindAttribLocation(m_programId, attrib, name);
}

GLuint ShaderBase::GetUniform(const char * name)
{
	return glGetUniformLocation(m_programId, name);
}

void ShaderBase::LoadFloat(GLuint location, float value)
{
	glUniform1f(location, value);
}

void ShaderBase::LoadInt(GLuint location, int value)
{
	glUniform1i(location, value);
}

void ShaderBase::LoadUInt(GLuint location, unsigned int value)
{
	glUniform1ui(location, value);
}

void ShaderBase::LoadVec3(GLuint location, glm::vec3 value)
{
	glUniform3f(location, value.x, value.y, value.z);
}

void ShaderBase::LoadBoolean(GLuint location, bool value)
{
	glUniform1f(location, (value ? 1 : 0));
}

void ShaderBase::LoadMatrix4(GLuint location, glm::mat4x4 value)
{
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void ShaderBase::SetProgramID(int id)
{
	m_programId = id;
}

void ShaderBase::SetVertexShaderID(int id)
{
	m_vertexShaderId = id;
}

void ShaderBase::SetFragmentShaderID(int id)
{
	m_fragmentShaderId = id;
}

int ShaderBase::GetProgramID()
{
	return m_programId;
}

int ShaderBase::GetVertexShaderID()
{
	return m_vertexShaderId;
}

int ShaderBase::GetFragmentShaderID()
{
	return m_fragmentShaderId;
}
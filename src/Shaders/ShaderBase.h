#ifndef SHADERBASE_H
#define SHADERBASE_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

class ShaderBase
{
public:
	ShaderBase();
	ShaderBase(const ShaderBase & other);
	~ShaderBase();
	void Start();
	void Stop();
	virtual void BindAttributes() = 0;
	virtual void GetAllUniforms() = 0;

	void SetProgramID(int id);
	void SetVertexShaderID(int id);
	void SetFragmentShaderID(int id);
	int GetProgramID();
	int GetVertexShaderID();
	int GetFragmentShaderID();

private:

protected:
	void BindAttrib(int attrib, const char * name);
	GLuint GetUniform(const char * name);
	void LoadFloat(GLuint location, float value);
	void LoadInt(GLuint location, int value);
	void LoadVec3(GLuint location, glm::vec3 value);
	void LoadBoolean(GLuint location, bool value);
	void LoadMatrix4(GLuint location, glm::mat4x4 value);

private:
	int m_programId;
	int m_vertexShaderId;
	int m_fragmentShaderId;
};

#endif
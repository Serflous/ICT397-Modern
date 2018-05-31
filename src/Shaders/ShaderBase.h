#ifndef SHADERBASE_H
#define SHADERBASE_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

	/**
	 * The base class for the shader interface classes.
	 */
class ShaderBase
{
public:
		/**
		 * Constructor
		 */
	ShaderBase();
		/**
		 * Copy constructor
		 */
	ShaderBase(const ShaderBase & other);
		/**
		 * Destructor
		 */
	~ShaderBase();
		/**
		 * Starts the shader program
		 */
	void Start();
		/**
		 * Stops the shader program
		 */
	void Stop();
		/**
		 * Pure virtual function that all shader interface classes must have for binding the attributes to the shader.
		 */
	virtual void BindAttributes() = 0;
		/**
		 * Pure virtual function that all shdaer interface classes must have for retrieving the location of the uniforms from the shader.
		 */
	virtual void GetAllUniforms() = 0;

		/**
		 * Sets the program id.
		 * @param[in] id The shader id.
		 */
	void SetProgramID(int id);
		/**
		 * Sets the vertex shader id.
		 * @param[in] id The vertex shader id
		 */
	void SetVertexShaderID(int id);
		/**
		 * The fragment shader id
		 * @param[in] id The fragment shader id
		 */
	void SetFragmentShaderID(int id);
		/**
		 * Returns the program id of the shader.
		 * @return int The id of the shader.
		 */
	int GetProgramID();
		/**
		 * Returns the vertex shader id.
		 * @return int The id of the Vertex shader.
		 */
	int GetVertexShaderID();
		/**
		 * Returns the fragment shader id
		 * @return int The id of the fragment shader.
		 */
	int GetFragmentShaderID();

private:

protected:
		/**
		 * Binds an attribute to a location for the shader.
		 * @param[in] attrib The number of the attribute to bind
		 * @param[in] name The name of the variable in the shader.
		 */
	void BindAttrib(int attrib, const char * name);
		/**
		 * Gets the location of a uniform in the shader.
		 * @param[in] name The name of the uniform.
		 * @return GLuint The location of the uniform.
		 */
	GLuint GetUniform(const char * name);
		/**
		 * Looads a float value to the shader.
		 * @param[in] location The location of the uniform
		 * @param[in] value The float value to load.
		 */
	void LoadFloat(GLuint location, float value);
		/**
		 * Loads an int value to the shader.
		 * @param[in] location The location of the uniform
		 * @param[in] value the int value to load
		 */
	void LoadInt(GLuint location, int value);
	void LoadUInt(GLuint location, unsigned int value);
		/**
		 * Loads a vec3 value to the shader
		 * @param[in] location The location of the uniform
		 * @param[in] value The vec3 value to load
		 */
	void LoadVec3(GLuint location, glm::vec3 value);
		/**
		 * Loads a boolean value to the shader - Unused
		 * @param[in] location The location of the uniform
		 * @param[in] value The bool value to load
		 */
	void LoadBoolean(GLuint location, bool value);
		/**
		 * Loads a mat4x4 value to the shader.
		 * @param[in] location The location of the uniform
		 * @param[in] value The mat4x4 value to load.
		 */
	void LoadMatrix4(GLuint location, glm::mat4x4 value);

private:
	int m_programId;
	int m_vertexShaderId;
	int m_fragmentShaderId;
};

#endif
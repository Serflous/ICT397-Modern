#ifndef SKYBOXSHADER_H
#define SKYBOXSHADER_H

#include <glm/mat4x4.hpp>

#include "ShaderBase.h"
#include "../GameObjects/Camera.h"

	/**
	* The shader interface class for the skybox
	*/
class SkyboxShader : public ShaderBase
{
public:
		/**
		* Default constructor
		*/
	SkyboxShader();
		/**
		* Default copy constructor
		*/
	SkyboxShader(const SkyboxShader & other);
		/**
		* Default destructor
		*/
	~SkyboxShader();

		/**
		* Binds all the attribues to the shader
		*/
	void BindAttributes();
		/**
		* Gets all the uniform locations from the shader
		*/
	void GetAllUniforms();
		/**
		* Loads the projection matrix to the shader
		* @param[in] projectionMatrix The projection matrix
		*/
	void LoadProjectionMatrix(glm::mat4x4 projectionMatrix);
		/**
		* Loads the view matrix from the camera to the shader.
		* @param[in] cam The camera.
		*/
	void LoadViewMatrix(Camera * cam);
private:
	GLuint m_location_projectionMatrix;
	GLuint m_location_viewMatrix;
};

#endif
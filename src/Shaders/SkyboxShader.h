#ifndef SKYBOXSHADER_H
#define SKYBOXSHADER_H

#include <glm/mat4x4.hpp>

#include "ShaderBase.h"
#include "../GameObjects/Camera.h"

class SkyboxShader : public ShaderBase
{
public:
	SkyboxShader();
	SkyboxShader(const SkyboxShader & other);
	~SkyboxShader();

	void BindAttributes();
	void GetAllUniforms();
	void LoadProjectionMatrix(glm::mat4x4 projectionMatrix);
	void LoadViewMatrix(Camera * cam);
private:
	GLuint m_location_projectionMatrix;
	GLuint m_location_viewMatrix;
};

#endif
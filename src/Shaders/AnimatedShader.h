#ifndef ANIMATEDSHADER_H
#define ANIMATEDSHADER_H

#include <glm/mat4x4.hpp>

#include "ShaderBase.h"
#include "../GameObjects/Camera.h"


class AnimatedShader : public ShaderBase
{
public:
	AnimatedShader();
	AnimatedShader(const AnimatedShader & other);
	~AnimatedShader();

	void BindAttributes();
	void GetAllUniforms();
	void LoadProjectionMatrix(glm::mat4x4 matrix);
	void LoadTransformationMatrix(glm::mat4x4 matrix);
	void LoadViewMatrix(Camera * cam);
private:
	GLuint m_location_boneTransforms;
	GLuint m_location_projectionMatrix;
	GLuint m_location_transformationMatrix;
	GLuint m_location_viewMatrix;
};

#endif
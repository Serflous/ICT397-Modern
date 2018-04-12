#ifndef TERRAINSHADER_H
#define TERRAINSHADER_H

#include <glm/mat4x4.hpp>

#include "ShaderBase.h"
#include "../GameObjects/Camera.h"
#include "../Util/MathHelper.h"

class TerrainShader : public ShaderBase
{
public:
	TerrainShader();
	TerrainShader(const TerrainShader & other);
	~TerrainShader();

	void BindAttributes();
	void GetAllUniforms();

	void LoadProjectionMatrix(glm::mat4x4 projectionMatrix);
	void LoadTransformationMatrix(glm::mat4x4 transformationMatrix);
	void LoadViewMatrix(Camera * cam);

private:

private:
	GLuint m_location_projectionMatrix;
	GLuint m_location_transformationMatrix;
	GLuint m_location_viewMatrix;
};

#endif
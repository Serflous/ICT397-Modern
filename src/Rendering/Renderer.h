#ifndef RENDERER_H
#define RENDERER_H

#include <glm/mat4x4.hpp>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "../Window/GlutWindow.h"
#include "../Shaders/StaticShader.h"
#include "../Resources/ModelOBJ.h"
#include "../Resources/Terrain.h"
#include "../Util/MathHelper.h"

class Renderer
{
public:
	Renderer();
	Renderer(StaticShader * shader);
	Renderer(const Renderer & other);
	~Renderer();

	void Init();

	void PrepareRender();
	void RenderModel(ModelOBJ * model);
	void RenderTerrain(Terrain * terrain);
	void SetView(Camera * camera);
	void StartShader();
	void StopShader();
private:
	void CreateProjectionMatrix();
private:
	StaticShader * m_shader;
	glm::mat4x4 m_projectionMatrix;
	const float FOV = 70.0f;
	const float NEAR_PLANE = 0.1f;
	const float FAR_PLANE = 1000.0f;
};

#endif
#ifndef RENDERER_H
#define RENDERER_H

#include <glm/mat4x4.hpp>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "../Resources/ResourceFactory.h"
#include "../Window/GlutWindow.h"
#include "../Shaders/ShaderBase.h"
#include "../Shaders/StaticShader.h"
#include "../Shaders/TerrainShader.h"
#include "../GameObjects/GameObject.h"
#include "../Resources/ModelOBJ.h"
#include "../Resources/Terrain.h"
#include "../Util/MathHelper.h"

class Terrain;
class GameObject;
class Renderer
{
public:
	Renderer();
	Renderer(const Renderer & other);
	~Renderer();

	void Init();

	void PrepareRender();
	void RenderGameObject(GameObject * obj);
	void RenderTerrain(Terrain * terrain);
	void SetView(Camera * camera);
private:
	void CreateProjectionMatrix();
private:
	ShaderBase * m_staticShader;
	ShaderBase * m_terrainShader;
	glm::mat4x4 m_projectionMatrix;
	const float FOV = 70.0f;
	const float NEAR_PLANE = 0.1f;
	const float FAR_PLANE = 1000.0f;
};

#endif
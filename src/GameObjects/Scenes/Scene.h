#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "../Camera.h"
#include "../../Rendering/Renderer.h"
#include "../../Resources/ModelOBJ.h"
#include "../../Resources/Terrain.h"

class Renderer;

class Scene
{
public:
	Scene();
	Scene(const Scene & other);
	~Scene();

	void SetCamera(Camera * camera);
	void AddModelOBJ(ModelOBJ * model);
	void SetRenderer(Renderer * renderer);
	void SetTerrain(Terrain * terrain);

	void RenderScene();
private:

private:
	Camera * m_camera;
	std::vector<ModelOBJ*> m_models;
	Renderer * m_renderer;
	Terrain * m_terrain;
};

#endif
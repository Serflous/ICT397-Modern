#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "../Camera.h"
#include "../../Rendering/Renderer.h"
#include "../GameObject.h"
#include "../../Resources/ModelOBJ.h"
#include "../../Resources/Terrain.h"

class Camera;
class Terrain;
class Renderer;

class Scene
{
public:
	Scene();
	Scene(const Scene & other);
	~Scene();

	void SetCamera(Camera * camera);
	void AddGameObject(GameObject * model);
	void SetRenderer(Renderer * renderer);
	void SetTerrain(Terrain * terrain);

	void RenderScene();
private:

private:
	Camera * m_camera;
	std::vector<GameObject*> m_gameObjects;
	Renderer * m_renderer;
	Terrain * m_terrain;
};

#endif
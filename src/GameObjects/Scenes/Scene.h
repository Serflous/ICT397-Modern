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

	/**
	 * The scene. Holds the terrain, camera, renderer, and a list of game objects.
	 */
class Scene
{
public:
		/**
		 * Constructor
		 */
	Scene();
		/**
		 * Copy constructor
		 */
	Scene(const Scene & other);
		/**
		 * Destructor
		 */
	~Scene();

		/**
		 * Sets the camera of the scene.
		 * @param[in] camera The camera.
		 */
	void SetCamera(Camera * camera);
		/**
		 * Adds a game object to the scene
		 * @param[in] obj The object to add the the scene
		 */
	void AddGameObject(GameObject * obj);
		/**
		 * Sets the renderer used by the scene
		 * @param[in] renderer The renderer used.
		 */
	void SetRenderer(Renderer * renderer);
		/**
		 * Sets the terrain of the scene
		 * @param[in] terrain The terrain used.
		 */
	void SetTerrain(Terrain * terrain);

		/**
		 * Renders the current scene.
		 */
	void RenderScene();
private:

private:
	Camera * m_camera;
	std::vector<GameObject*> m_gameObjects;
	Renderer * m_renderer;
	Terrain * m_terrain;
};

#endif
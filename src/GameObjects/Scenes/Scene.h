#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "../Camera.h"
#include "../../Rendering/Renderer.h"
#include "../GameObject.h"
#include "../../Resources/Modelling/ModelOBJ.h"
#include "../../Resources/Terrain.h"
#include "../../Resources/Skybox.h"
#include "../../Resources/GUI/GUI.h"
#include "../RayPicker.h"
#include "../Player.h"
#include "../Agent.h"

class Camera;
class Terrain;
class Renderer;
class RayPicker;
class Player;
class Agent;

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
	void AddAgent(Agent * agent);
	void SetRenderer(Renderer * renderer);
		/**
		 * Sets the terrain of the scene
		 * @param[in] terrain The terrain used.
		 */
	void SetTerrain(Terrain * terrain);

	void SetSkybox(Skybox * skybox);
	void SetGUI(GUI * gui);
	void SetPlayer(Player * player);

		/**
		 * Renders the current scene.
		 */
	void RenderScene();
	void UpdateScene(int deltaTime);
private:

private:
	Camera * m_camera;
	Player * m_player;
	std::vector<GameObject*> m_gameObjects;
	std::vector<Agent*> m_agents;
	Renderer * m_renderer;
	Terrain * m_terrain;
	Skybox * m_skybox;
	GUI * m_gui;
	RayPicker * m_rayPicker;
};

#endif
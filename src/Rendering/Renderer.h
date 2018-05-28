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
#include "../Shaders/AnimatedShader.h"
#include "../Shaders/SkyboxShader.h"
#include "../Shaders/GUIShader.h"
#include "../GameObjects/GameObject.h"
#include "../Resources/Modelling/ModelOBJ.h"
#include "../Resources/Terrain.h"
#include "../Resources/Skybox.h"
#include "../Util/MathHelper.h"
#include "../Resources/GUI/GUI.h"

class Terrain;
class GameObject;

	/**
	 * Class for rendering objects to OpenGL.
	 */
class Renderer
{
public:
		/**
		 * Constructor
		 */
	Renderer();
		/**
		 * Copy constructor
		 */
	Renderer(const Renderer & other);
		/**
		 * Destructor
		 */
	~Renderer();

		/**
		 * Initializes the renderer. Prepares the shaders
		 */
	void Init();

		/**
		 * Prepares for rendering. Clearing the screen and enabling options.
		 */
	void PrepareRender();
		/**
		 * Renders a GameObject.
		 * @param[in] obj The object to draw to the screen.
		 */
	void RenderGameObject(GameObject * obj);
		/**
		 * Renders a Terrain object to the screen
		 * @param[in] terrain The terrain to draw
		 */
	void RenderTerrain(Terrain * terrain);
		/**
		 * Sets the view to the view of the camera.
		 * @param[in] camera The camera.
		 */
	void RenderSkybox(Skybox * skybox);
	void SetView(Camera * camera);

	void RenderGUI(GUI * gui);
private:
		/**
		 * Creates a projection matrix using GLM
		 */
	void CreateProjectionMatrix();
private:
	ShaderBase * m_staticShader;
	ShaderBase * m_terrainShader;
	ShaderBase * m_animatedShader;
	ShaderBase * m_skyboxShader;
	ShaderBase * m_guiShader;
	glm::mat4x4 m_projectionMatrix;
	const float FOV = 70.0f;
	const float NEAR_PLANE = 0.1f;
	const float FAR_PLANE = 1000.0f;
};

#endif
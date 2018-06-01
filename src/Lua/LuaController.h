#ifndef LUACONTROLLER_H
#define LUACONTROLLER_H

#include <lua.hpp>
#include <luabind/luabind.hpp>

#include <iostream>
#include <vector>


#include "../Resources/ResourceFactory.h"
#include "../GameObjects/Scenes/Scene.h"
#include "../GameObjects/MonsterObject.h"
#include "../Resources/Texture2D.h"

	/**
	 * Singleton class for loading in game object from LUA
	 */
class LuaController
{
public:
		/**
		 * Returns the instance to the singleton LuaController object. If it hasnt been created yet, it will be created.
		 * @return LuaController* A pointer to the singleton object.
		 */
	static LuaController * GetInstance();

		/**
		 * Processes a LUA file and loads in the items
		 * @param[in] filename The location of the shader file
		 */
	void ProcessLuaFile(const char * filename);
		/**
		 * Creates a scene file based on what has been loaded.
		 * @return Scene* A pointer to a scene file.
		 */
	Scene * CreateScene();
	
private:
		/**
		 * Constructor
		 */
	LuaController();
		/**
		 * Copy constructor
		 */
	LuaController(const LuaController & other);
		/**
		 * Destructor
		 */
	~LuaController();
		/**
		 * Loads a texture into the engine.
		 * @param[in] filename The filename of the texture.
		 * @param[in] x The width of the texture.
		 * @param[in] y The height of the texture.
		 * @return int The ID of the texture.
		 */
	static int LoadTexture(const char * filename, int x, int y);
		/**
		 * Loads a model into the engine
		 * @param[in] modelFilename The filename of the model.
		 * @param[in] textureId The ID of the texture.
		 * @return int The id of the model
		 */
	static int LoadModelOBJ(const char * modelFilename, int textureId);
		/**
		 * Loads a game object into the game
		 * @param[in] modelId The id of the model.
		 * @param[in] posX The x position of the object.
		 * @param[in] posY The y position of the object.
		 * @param[in] posZ The z position of the object.
		 * @param[in] rotX The x rotation of the object.
		 * @param[in] rotY The y rotation of the object.
		 * @param[in] rotZ The z rotation of the object.
		 * @param[in] scaleX The x scale of the object.
		 * @param[in] scaleY The y scale of the object.
		 * @param[in] scaleZ The z scale of the object.
		 */
	static int LoadGameObject(int modelId, float posX, float posZ, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ);
		/**
		 * Loads a monster into the game -- Functionally the same of game object for the time being
		 * @param[in] modelId The id of the model.
		 * @param[in] posX The x position of the object.
		 * @param[in] posY The y position of the object.
		 * @param[in] posZ The z position of the object.
	 	 * @param[in] rotX The x rotation of the object.
		 * @param[in] rotY The y rotation of the object.
		 * @param[in] rotZ The z rotation of the object.
		 * @param[in] scaleX The x scale of the object.
		 * @param[in] scaleY The y scale of the object.
		 * @param[in] scaleZ The z scale of the object.
		 */
	static int LoadMonster(int modelId, float posX, float posZ, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ);
		/**
		 * Sets the terrain of the scene.
		 * @param[in] heightmap The location of the heightmap file.
		 * @param[in] heightMapSize The size of the heightmap file.
		 * @param[in] baseTexId The id of the base texture.
		 * @param[in] rTexId The id of the r texture.
		 * @param[in] gTexId The id of the g texture.
		 * @param[in] bTexId The id of the b texture.
		 * @param[in] detailMapId The id of the detail map.
		 * @param[in] scaleX The x scale of the terrain.
		 * @param[in] scaleY The y scale of the terrain.
		 * @param[in] scaleZ The z scale of the terrain.
		 */
	static void SetTerrain(const char * heightmap, int heightMapSize, int baseTexId, int rTexId, int gTexId, int bTexId, int detailMapId, float scaleX, float scaleY, float scaleZ);
		/**
		 * Sets the camera to the specified position.
		 * @param[in] posX The x position of the camera.
		 * @param[in] posY The y position of the camera.
		 * @param[in] posZ The z position of the camera.
		 * @param[in] pitch The pitch of the camera.
		 * @param[in] yaw The yaw of the camera.
		 * @param[in] roll The roll of the camera.
		 */
	static void SetCamera(float posX, float posY, float posZ, float pitch, float yaw, float roll);
		/**
		* Sets the skybox of the game.
		* @param[in] right The right texture.
		* @param[in] left The left texture.
		* @param[in] top The top texture.
		* @param[in] bottom The bottom texture.
		* @param[in] back The back texture.
		* @param[in] front The front texture.
		*/
	static void SetSkybox(const char * right, const char * left, const char * top, const char * bottom, const char * back, const char * front);
private:
	static LuaController * m_instance;

	Scene * m_currentScene;
	std::vector<Texture2D*> m_loadedTextures;
	std::vector<ModelOBJ*> m_loadedModelOBJs;
	std::vector<GameObject*> m_loadedGameObjects;
	std::vector<Agent*> m_loadedAgents;
	Terrain * m_loadedTerrain;
	Camera * m_loadedCamera;
	Skybox * m_loadedSkybox;
};

#endif
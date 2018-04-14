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

class LuaController
{
public:
	static LuaController * GetInstance();

	void ProcessLuaFile(const char * filename);
	Scene * CreateScene();
	
private:
	LuaController();
	LuaController(const LuaController & other);
	~LuaController();
	static int LoadTexture(const char * filename, int x, int y);
	static int LoadModelOBJ(const char * modelFilename, int textureId);
	static int LoadGameObject(int modelId, float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ);
	static int LoadMonster(int modelId, float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ);
	static void SetTerrain(const char * heightmap, int heightMapSize, int baseTexId, int rTexId, int gTexId, int bTexId, int detailMapId, float scaleX, float scaleY, float scaleZ);
	static void SetCamera(float posX, float posY, float posZ, float pitch, float yaw, float roll);
private:
	static LuaController * m_instance;

	Scene * m_currentScene;
	std::vector<Texture2D*> m_loadedTextures;
	std::vector<ModelOBJ*> m_loadedModelOBJs;
	std::vector<GameObject*> m_loadedGameObjects;
	Terrain * m_loadedTerrain;
	Camera * m_loadedCamera;

};

#endif
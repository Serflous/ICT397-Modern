#include "LuaController.h"

LuaController * LuaController::m_instance;

LuaController::LuaController()
{

}

LuaController::LuaController(const LuaController & other)
{

}

LuaController::~LuaController()
{

}

LuaController * LuaController::GetInstance()
{
	if (!m_instance)
	{
		m_instance = new LuaController();
	}
	return m_instance;
}

void LuaController::ProcessLuaFile(const char * filename)
{
	lua_State * lua = lua_open();
	luaL_openlibs(lua);
	luabind::open(lua);
	luabind::module(lua)[luabind::def("LoadTexture", &LoadTexture)];
	luabind::module(lua)[luabind::def("LoadModelOBJ", &LoadModelOBJ)];
	luabind::module(lua)[luabind::def("LoadGameObject", &LoadGameObject)];
	luabind::module(lua)[luabind::def("LoadMonster", &LoadMonster)];
	luabind::module(lua)[luabind::def("SetTerrain", &SetTerrain)];
	luabind::module(lua)[luabind::def("SetCamera", &SetCamera)];
	luabind::module(lua)[luabind::def("SetSkybox", &SetSkybox)];

	luaL_dofile(lua, filename);
}

int LuaController::LoadTexture(const char * filename, int x, int y)
{
	ResourceFactory * factory = ResourceFactory::GetInstance();
	Texture2D * texture = nullptr;
	factory->LoadTexture(filename, x, y, &texture);
	m_instance->m_loadedTextures.push_back(texture);
	return m_instance->m_loadedTextures.size() - 1;
}

int LuaController::LoadModelOBJ(const char * modelFilename, int textureId)
{
	ResourceFactory * factory = ResourceFactory::GetInstance();
	ModelOBJ * model = nullptr;
	factory->LoadOBJ(modelFilename, &model, m_instance->m_loadedTextures[textureId]);
	m_instance->m_loadedModelOBJs.push_back(model);
	return m_instance->m_loadedModelOBJs.size() - 1;
}

int LuaController::LoadGameObject(int modelId, float posX, float posZ, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ)
{
	ResourceFactory * factory = ResourceFactory::GetInstance();
	ModelOBJ * model = m_instance->m_loadedModelOBJs[modelId];
	GameObject * gameObject = nullptr;
	factory->LoadGameObject(model, glm::vec3(posX, 0, posZ), glm::vec3(rotX, rotY, rotZ), glm::vec3(scaleX, scaleY, scaleZ), &gameObject);
	m_instance->m_loadedGameObjects.push_back(gameObject);
	return m_instance->m_loadedGameObjects.size() - 1;
}

int LuaController::LoadMonster(int modelId, float posX, float posZ, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ)
{
	ResourceFactory * factory = ResourceFactory::GetInstance();
	ModelOBJ * model = m_instance->m_loadedModelOBJs[modelId];
	GameObject * gameObject = new MonsterObject();
	factory->LoadGameObject(model, glm::vec3(posX, 0, posZ), glm::vec3(rotX, rotY, rotZ), glm::vec3(scaleX, scaleY, scaleZ), &gameObject);
	Agent * agent = new Agent();
	agent->SetGameObject(gameObject);
	//m_instance->m_loadedGameObjects.push_back(gameObject);
	m_instance->m_loadedAgents.push_back(agent);
	return m_instance->m_loadedAgents.size() - 1;
}

void LuaController::SetTerrain(const char * heightmap, int heightmapSize, int baseTexId, int rTexId, int gTexId, int bTexId, int detailMapId, float scaleX, float scaleY, float scaleZ)
{
	ResourceFactory * factory = ResourceFactory::GetInstance();
	Terrain * terrain = new Terrain();
	TerrainTextures * textures = new TerrainTextures();
	textures->SetBaseTexture(&(m_instance->m_loadedTextures[baseTexId]));
	textures->SetDetailMap(&(m_instance->m_loadedTextures[detailMapId]));
	textures->AddTexture(&(m_instance->m_loadedTextures[rTexId]));
	textures->AddTexture(&(m_instance->m_loadedTextures[gTexId]));
	textures->AddTexture(&(m_instance->m_loadedTextures[bTexId]));
	factory->LoadTerrain(heightmap, heightmapSize, &terrain, &textures, glm::vec3(scaleX, scaleY, scaleZ));
	m_instance->m_loadedTerrain = terrain;
}

void LuaController::SetCamera(float posX, float posY, float posZ, float pitch, float yaw, float roll)
{
	Camera * cam = new Camera(posX, posY, posZ);
	m_instance->m_loadedCamera = cam;
}

Scene * LuaController::CreateScene()
{
	m_currentScene = new Scene();
	Player * player = new Player();
	m_currentScene->SetPlayer(player);
	m_currentScene->SetCamera(m_loadedCamera);
	m_currentScene->SetTerrain(m_loadedTerrain);
	m_currentScene->SetSkybox(m_loadedSkybox);
	std::vector<GameObject*>::iterator iter;
	for (iter = m_loadedGameObjects.begin(); iter != m_loadedGameObjects.end(); iter++)
	{
		GameObject * object = (*iter);
		m_currentScene->AddGameObject(object);
	}
	std::vector<Agent*>::iterator agentIter;
	for (agentIter = m_loadedAgents.begin(); agentIter != m_loadedAgents.end(); agentIter++)
	{
		Agent * agent = (*agentIter);
		agent->SetPlayer(player);
		m_currentScene->AddAgent(agent);
	}

	return m_currentScene;
}

void LuaController::SetSkybox(const char * right, const char * left, const char * top, const char * bottom, const char * back, const char * front)
{
	m_instance->m_loadedSkybox = nullptr;
	std::vector<const char *> skyboxTextures;
	skyboxTextures.push_back(right);
	skyboxTextures.push_back(left);
	skyboxTextures.push_back(top);
	skyboxTextures.push_back(bottom);
	skyboxTextures.push_back(back);
	skyboxTextures.push_back(front);
	ResourceFactory::GetInstance()->LoadSkybox(&m_instance->m_loadedSkybox, skyboxTextures, 512);
}
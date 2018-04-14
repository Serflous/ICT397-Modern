#include "Window/GlutWindow.h"
#include "Resources/ResourceFactory.h"
#include "Shaders/ShaderBase.h"
#include "Shaders/StaticShader.h"
#include "GameObjects/Camera.h"
#include "Rendering/Renderer.h"
#include "GameObjects/Scenes/Scene.h"
#include "Resources/Terrain.h"
#include "Resources/TerrainTextures.h"
#include "GameObjects/StaticObject.h"

#include "Collision/AABB.h"

int main(int argc, char ** argv)
{
	GlutWindow * window = GlutWindow::GetInstance();
	ResourceFactory * resourceFactory = ResourceFactory::GetInstance();
	Camera * camera = new Camera(512, 0, 512);
	Scene * scene = new Scene();
	Terrain * terrain = new Terrain();
	Texture2D * baseTextureTerrain = nullptr;
	Texture2D * rockTextureTerrain = nullptr;
	Texture2D * rockIceTextureTerrain = nullptr;
	Texture2D * dirtTextureTerrain = nullptr;
	Texture2D * detailMap = nullptr;
	TerrainTextures * terrainTextures = new TerrainTextures();
	GameObject * rock = nullptr;
	GameObject * rockTwo = nullptr;
	Texture2D * rockModelTexture = nullptr;
	ModelOBJ * rockModel = nullptr;
	
	window->InitializeGlutWindow(&argc, argv);

	Renderer * renderer = new Renderer();

	resourceFactory->LoadTexture("res/Textures/Terrain.raw", 128, 128, &baseTextureTerrain);
	resourceFactory->LoadTexture("res/Textures/Rock.raw", 128, 128, &rockTextureTerrain);
	resourceFactory->LoadTexture("res/Textures/RockIce.raw", 128, 128, &rockIceTextureTerrain);
	resourceFactory->LoadTexture("res/Textures/Dirt.raw", 128, 128, &dirtTextureTerrain);
	resourceFactory->LoadTexture("res/Textures/DetailMap.raw", 128, 128, &detailMap);
	resourceFactory->LoadTexture("res/Textures/rockTextureWrapped.raw", 1024, 1024, &rockModelTexture);
	resourceFactory->LoadOBJ("res/Models/rock.obj", &rockModel, rockModelTexture);

	terrainTextures->SetBaseTexture(&baseTextureTerrain);
	terrainTextures->AddTexture(&dirtTextureTerrain);
	terrainTextures->AddTexture(&rockTextureTerrain);
	terrainTextures->AddTexture(&rockIceTextureTerrain);
	terrainTextures->SetDetailMap(&detailMap);
	resourceFactory->LoadTerrain("res/Heightmaps/heightmapLarge.raw", 1024, &terrain, &terrainTextures, glm::vec3(1, 0.6f, 1));
	
	resourceFactory->LoadGameObject(rockModel, glm::vec3(520, 57, 512), glm::vec3(0, 90, 0), glm::vec3(1, 1, 1), &rock);
	resourceFactory->LoadGameObject(rockModel, glm::vec3(512, 60, 489), glm::vec3(45, 0, 0), glm::vec3(1, 1, 1), &rockTwo);
	//resourceFactory->LoadGameObject(rockModel, glm::vec3(512, 57, 512), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), &rockTwo);

	renderer->Init();

	scene->SetCamera(camera);
	scene->SetRenderer(renderer);
	scene->SetTerrain(terrain);
	scene->AddGameObject(rock);
	scene->AddGameObject(rockTwo);

	window->BeginMainGameLoop(scene);
}
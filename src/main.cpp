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
	StaticObject * rock = new StaticObject();
	StaticObject * rockTwo = new StaticObject();
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
	
	rock->SetModel(&rockModel);
	rock->SetPosition(glm::vec3(512, 57, 512));
	rock->SetRotation(glm::vec3(0, 90, 0));
	rock->SetScale(glm::vec3(1, 1, 1));

	rockTwo->SetModel(&rockModel);
	rockTwo->SetPosition(glm::vec3(512, 60, 512));
	rockTwo->SetRotation(glm::vec3(0, 90, 0));
	rockTwo->SetScale(glm::vec3(1, 1, 1));

	renderer->Init();

	scene->SetCamera(camera);
	scene->SetRenderer(renderer);
	scene->SetTerrain(terrain);
	//scene->AddModelOBJ(rockModel);
	scene->AddGameObject(rock);
	scene->AddGameObject(rockTwo);

	window->BeginMainGameLoop(scene);
}
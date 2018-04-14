#include "Window/GlutWindow.h"
#include "Resources/ResourceFactory.h"
#include "Shaders/ShaderBase.h"
#include "Shaders/StaticShader.h"
#include "GameObjects/Camera.h"
#include "Rendering/Renderer.h"
#include "GameObjects/Scenes/Scene.h"
#include "Resources/Terrain.h"
#include "Resources/TerrainTextures.h"

int main(int argc, char ** argv)
{
	GlutWindow * window = GlutWindow::GetInstance();
	ResourceFactory * resourceFactory = ResourceFactory::GetInstance();
	Texture2D * rockTexture = nullptr;
	ModelOBJ * rockModel = nullptr;
	Camera * camera = new Camera(512, 0, 512);
	Scene * scene = new Scene();
	Terrain * terrain = new Terrain();
	Texture2D * baseTextureTerrain = nullptr;
	Texture2D * rockTextureTerrain = nullptr;
	Texture2D * rockIceTextureTerrain = nullptr;
	Texture2D * dirtTextureTerrain = nullptr;
	TerrainTextures * terrainTextures = new TerrainTextures();
	
	window->InitializeGlutWindow(&argc, argv);

	Renderer * renderer = new Renderer();

	resourceFactory->LoadTexture("res/Textures/kartRedBaked.raw", 2048, 2048, &rockTexture);
	resourceFactory->LoadOBJ("res/Models/kartRedBaked.obj", &rockModel, rockTexture);
	resourceFactory->LoadTexture("res/Textures/Terrain.raw", 128, 128, &baseTextureTerrain);
	resourceFactory->LoadTexture("res/Textures/Rock.raw", 128, 128, &rockTextureTerrain);
	resourceFactory->LoadTexture("res/Textures/RockIce.raw", 128, 128, &rockIceTextureTerrain);
	resourceFactory->LoadTexture("res/Textures/Dirt.raw", 128, 128, &dirtTextureTerrain);

	terrainTextures->SetBaseTexture(&baseTextureTerrain);
	terrainTextures->AddTexture(&dirtTextureTerrain);
	terrainTextures->AddTexture(&rockTextureTerrain);
	terrainTextures->AddTexture(&rockIceTextureTerrain);
	resourceFactory->LoadTerrain("res/Heightmaps/heightmapLarge.raw", 1024, &terrain, &terrainTextures, glm::vec3(1, 0.6f, 1));
	
	renderer->Init();

	scene->SetCamera(camera);
	scene->AddModelOBJ(rockModel);
	scene->SetRenderer(renderer);
	scene->SetTerrain(terrain);

	window->BeginMainGameLoop(scene);
}
#include "Window/GlutWindow.h"
#include "Resources/ResourceFactory.h"
#include "Shaders/ShaderBase.h"
#include "Shaders/StaticShader.h"
#include "GameObjects/Camera.h"
#include "Rendering/Renderer.h"
#include "GameObjects/Scenes/Scene.h"
#include "Resources/Terrain.h"

int main(int argc, char ** argv)
{
	GlutWindow * window = GlutWindow::GetInstance();
	ResourceFactory * resourceFactory = ResourceFactory::GetInstance();
	Texture2D * rockTexture = nullptr;
	ModelOBJ * rockModel = nullptr;
	ShaderBase * shader = new StaticShader();
	Camera * camera = new Camera();
	Renderer * renderer = new Renderer((StaticShader*)shader);
	Scene * scene = new Scene();
	Terrain * terrain = new Terrain();
	
	window->InitializeGlutWindow(&argc, argv);

	terrain->SetScale(glm::vec3(1.0f, 1.0f, 1.0f));

	resourceFactory->LoadTexture("res/Textures/kartRedBaked.raw", 2048, 2048, &rockTexture);
	resourceFactory->LoadOBJ("res/Models/kartRedBaked.obj", &rockModel, rockTexture);
	resourceFactory->LoadShader("res/Shaders/staticShader.vert", "res/Shaders/staticShader.frag", &shader);
	resourceFactory->LoadTerrain("res/Heightmaps/heightmap.raw", 512, &terrain);
	
	renderer->Init();

	scene->SetCamera(camera);
	scene->AddModelOBJ(rockModel);
	scene->SetRenderer(renderer);
	scene->SetTerrain(terrain);

	window->BeginMainGameLoop(scene);
}
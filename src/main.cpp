#include "Util/IniLoader.h"
#include "Window/GlutWindow.h"
#include "Rendering/Renderer.h"
#include "GameObjects/Scenes/Scene.h"
#include "Resources/Modelling/ModelAnimated.h"

#include "Lua/LuaController.h"

int main(int argc, char ** argv)
{
	IniLoader loader;
	loader.LoadIniFile("config.ini");

	GlutWindow * window = GlutWindow::GetInstance();
	window->InitializeGlutWindow(&argc, argv, loader);

	LuaController * lua = LuaController::GetInstance();
	lua->ProcessLuaFile("res/scripts/level.lua");
	Scene * scene = lua->CreateScene();

	Renderer * renderer = new Renderer();
	renderer->Init();

	ModelAnimated * model = nullptr;
	Texture2D * tex = nullptr;
	GameObject * obj = nullptr;
	ResourceFactory::GetInstance()->LoadTexture("res/textures/Rock-Texture-Surface.raw", 2592, 1944, &tex);
	ResourceFactory::GetInstance()->LoadCollada("res/models/Rock1.dae", &model, tex);
	ResourceFactory::GetInstance()->LoadGameObject(model, glm::vec3(513, 71, 471), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), &obj);
	scene->AddGameObject(obj);

	scene->SetRenderer(renderer);
	window->BeginMainGameLoop(scene);
}
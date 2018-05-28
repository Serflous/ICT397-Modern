#include "Util/IniLoader.h"
#include "Window/GlutWindow.h"
#include "Rendering/Renderer.h"
#include "GameObjects/Scenes/Scene.h"
#include "Resources/Modelling/ModelAnimated.h"
#include "Resources/Skybox.h"
#include "Resources/GUI/GUI.h"

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

	GUI * gui = nullptr;
	ResourceFactory::GetInstance()->LoadGUIQuad(&gui);
	Texture2D * heartTex = nullptr;
	ResourceFactory::GetInstance()->LoadTexture("res/textures/heart.raw", 32, 32, &heartTex);
	TextureGUI * heartTexGUI = new TextureGUI(heartTex, glm::vec2(-0.85, -0.85), glm::vec2(0, 0), glm::vec2(0.05, 0.05));
	gui->AddTexture(heartTexGUI);

	scene->SetGUI(gui);
	scene->SetRenderer(renderer);
	window->BeginMainGameLoop(scene);
}
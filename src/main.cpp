#include "Util/IniLoader.h"
#include "Window/GlutWindow.h"
#include "Rendering/Renderer.h"
#include "GameObjects/Scenes/Scene.h"

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

	scene->SetRenderer(renderer);
	window->BeginMainGameLoop(scene);
}
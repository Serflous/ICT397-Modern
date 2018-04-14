#include "Window/GlutWindow.h"
#include "Rendering/Renderer.h"
#include "GameObjects/Scenes/Scene.h"

#include "Lua/LuaController.h"

int main(int argc, char ** argv)
{
	GlutWindow * window = GlutWindow::GetInstance();
	window->InitializeGlutWindow(&argc, argv);

	LuaController * lua = LuaController::GetInstance();
	lua->ProcessLuaFile("res/scripts/level.lua");
	Scene * scene = lua->CreateScene();

	Renderer * renderer = new Renderer();
	renderer->Init();

	scene->SetRenderer(renderer);
	window->BeginMainGameLoop(scene);
}
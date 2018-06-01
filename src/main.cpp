#include <GL/glew.h>
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

	GUI * gui = nullptr;
	ResourceFactory::GetInstance()->LoadGUIQuad(&gui);
	Texture2D * heartTex = nullptr;
	ResourceFactory::GetInstance()->LoadTexture("res/textures/heart.raw", 32, 32, &heartTex);
	TextureGUI * heartTexGUI = new TextureGUI(heartTex, glm::vec2(-0.85, -0.85), glm::vec2(0, 0), glm::vec2(0.05, 0.05));
	Texture2D * crosshairTex = nullptr;
	ResourceFactory::GetInstance()->LoadTexture("res/textures/crosshair.raw", 32, 32, &crosshairTex);
	TextureGUI * crosshairTexGUI = new TextureGUI(crosshairTex, glm::vec2(0, 0), glm::vec2(0, 0), glm::vec2(0.03, 0.03));
	gui->AddTexture(heartTexGUI);
	gui->AddTexture(crosshairTexGUI);

	scene->SetGUI(gui);
	scene->SetRenderer(renderer);
	window->BeginMainGameLoop(scene);
}
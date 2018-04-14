#ifndef GLUTWINDOW_H
#define GLUTWINDOW_H

#include <GL/glew.h>
#ifdef _WIN32
#include <GL/freeglut.h>
#elif __APPLE__
#include <GLUT/glut.h>
#endif

#include "../Input/InputManager.h"
#include "../GameObjects/Scenes/Scene.h"

class Scene;

class GlutWindow
{
public:
	static GlutWindow * GetInstance();

	int InitializeGlutWindow(int * argc, char ** argv);
	void BeginMainGameLoop(Scene * scene);
	void DrawCallback();
	void ReshapeCallback(int w, int h);
	void GetWindowSize(int & x, int & y);

	static void StaticDrawCallback();
	static void StaticReshapeCallback(int w, int h);
	static void StaticKeyboardCallback(unsigned char key, int x, int y);
	static void StaticKeyboardUpCallback(unsigned char key, int x, int y);
	static void StaticSpecialKeyboardCallback(int key, int x, int y);
	static void StaticSpecialKeyboardUpCallback(int key, int x, int y);
	static void StaticMouseCallback(int button, int state, int x, int y);
	static void StaticMousePositionCallback(int x, int y);
	static void APIENTRY GLMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
private:
	GlutWindow();
	~GlutWindow();
	GlutWindow(const GlutWindow & other);
private:
	const int INIT_WINDOW_SIZE_X = 1280;
	const int INIT_WINDOW_SIZE_Y = 720;
	const int INIT_WINDOW_POS_X = -1;
	const int INIT_WINDOW_POS_Y = -1;
	const char * WINDOW_TITLE = "ICT397 Game";

	Scene * m_scene;
	int m_winX, m_winY;

	bool m_wireframe = false;

	static GlutWindow * m_instance;
};
#endif
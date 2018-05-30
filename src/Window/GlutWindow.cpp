#include "GlutWindow.h"

GlutWindow * GlutWindow::m_instance;

GlutWindow::GlutWindow()
{

}

GlutWindow::~GlutWindow()
{

}

GlutWindow::GlutWindow(const GlutWindow & other)
{

}

GlutWindow * GlutWindow::GetInstance()
{
	if (!m_instance)
	{
		m_instance = new GlutWindow();
	}
	return m_instance;
}

int GlutWindow::InitializeGlutWindow(int * argc, char ** argv, IniLoader loader)
{
	glutInit(argc, argv);
	glutSetOption(GLUT_MULTISAMPLE, 16);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	m_winX = atoi(loader.GetProperty("engine_window/width"));
	m_winY = atoi(loader.GetProperty("engine_window/height"));
	int initPosX = atoi(loader.GetProperty("engine_window/posX"));
	int initPosY = atoi(loader.GetProperty("engine_window/posY"));
	glutInitWindowPosition(initPosX, initPosY);
	glutInitWindowSize(atoi(loader.GetProperty("engine_window/width")), atoi(loader.GetProperty("engine_window/height")));//INIT_WINDOW_SIZE_X, INIT_WINDOW_SIZE_Y);
	glutCreateWindow(loader.GetProperty("engine_window/title"));//WINDOW_TITLE);
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		std::cerr << "Glew error: " << glewGetErrorString(err) << std::endl;
	}

	glutDisplayFunc(StaticDrawCallback);
	glutIdleFunc(StaticDrawCallback);
	glutTimerFunc(16, StaticUpdateCallback, 0);
	glutReshapeFunc(StaticReshapeCallback);
	glutKeyboardFunc(StaticKeyboardCallback);
	glutKeyboardUpFunc(StaticKeyboardUpCallback);
	glutSpecialFunc(StaticSpecialKeyboardCallback);
	glutSpecialUpFunc(StaticSpecialKeyboardUpCallback);
	glutMouseFunc(StaticMouseCallback);
	glutMotionFunc(StaticMousePositionCallback);
	glutPassiveMotionFunc(StaticMousePositionCallback);
	glClearColor(0.3922f, 0.5843f, 0.9294f, 1.0f);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	glDebugMessageCallback(StaticMessageCallback, nullptr);
	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, true);

	glutSetCursor(GLUT_CURSOR_NONE);
	return 0;
}

void GlutWindow::DrawCallback()
{
	m_scene->RenderScene();

	glutSwapBuffers();
}

void GlutWindow::ReshapeCallback(int w, int h)
{
	glViewport(0, 0, w, h);
	m_winX = w;
	m_winY = h;
}

void GlutWindow::Update(int value)
{
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	int deltaTime = currentTime - value;
	glutTimerFunc(16, StaticUpdateCallback, currentTime);

	if (InputManager::GetInstance()->GetKeyState('k') == KS_KEY_PRESSED)
	{
		m_wireframe = !m_wireframe;
		if (m_wireframe)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	if (InputManager::GetInstance()->GetKeyState('x') == KS_KEY_PRESSED)
	{
		glutExit();
	}
	m_scene->UpdateScene(deltaTime);
}

void GlutWindow::BeginMainGameLoop(Scene * scene)
{
	m_scene = scene;
	glutMainLoop();
}

void GlutWindow::StaticDrawCallback()
{
	m_instance->DrawCallback();
}

void GlutWindow::StaticReshapeCallback(int w, int h)
{
	m_instance->ReshapeCallback(w, h);
}

void GlutWindow::StaticKeyboardCallback(unsigned char key, int x, int y)
{
	InputManager::GetInstance()->KeyCallback(key, true);
}

void GlutWindow::StaticKeyboardUpCallback(unsigned char key, int x, int y)
{
	InputManager::GetInstance()->KeyCallback(key, false);
}

void GlutWindow::StaticSpecialKeyboardCallback(int key, int x, int y)
{
	InputManager::GetInstance()->KeyCallback(127 + key, true);
}

void GlutWindow::StaticSpecialKeyboardUpCallback(int key, int x, int y)
{
	InputManager::GetInstance()->KeyCallback(127 + key, false);
}

void GlutWindow::StaticMouseCallback(int button, int state, int x, int y)
{
	InputManager::GetInstance()->MouseCallback(button, state, x, y);
}

void GlutWindow::StaticMousePositionCallback(int x, int y)
{
	InputManager::GetInstance()->MouseMotionCallback(x, y);
}

void GlutWindow::GetWindowSize(int & x, int & y)
{
	x = m_winX;
	y = m_winY;
}

void GlutWindow::StaticUpdateCallback(int value)
{
	m_instance->Update(value);
}

void GlutWindow::StaticMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
	using namespace std;
	if (source == GL_DEBUG_SOURCE_API)
		return;
	cout << endl;
	cout << "Source: ";
	switch (source)
	{
		case GL_DEBUG_SOURCE_API:
			cout << "API.";
			break;
		case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
			cout << "Window System.";
			break;
		case GL_DEBUG_SOURCE_SHADER_COMPILER:
			cout << "Shader.";
			break;
		case GL_DEBUG_SOURCE_THIRD_PARTY:
			cout << "Third Party.";
			break;
		case GL_DEBUG_SOURCE_APPLICATION:
			cout << "Application.";
			break;
		case GL_DEBUG_SOURCE_OTHER:
			cout << "Other.";
			break;
	}
	cout << endl;
	cout << "Message: " << message << endl;
	cout << "Type: ";
	switch (type)
	{
		case GL_DEBUG_TYPE_ERROR:
			cout << "Error";
			break;
		case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
			cout << "Deprecated Behaviour";
			break;
		case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
			cout << "Undefined_Behaviour";
			break;
		case GL_DEBUG_TYPE_PORTABILITY:
			cout << "Portability";
			break;
		case GL_DEBUG_TYPE_PERFORMANCE:
			cout << "Performance";
			break;
		case GL_DEBUG_TYPE_OTHER:
			cout << "Other";
			break;
	}
	cout << endl;
	cout << "Severity: ";
	switch (severity)
	{
		case GL_DEBUG_SEVERITY_LOW:
			cout << "Low";
			break;
		case GL_DEBUG_SEVERITY_MEDIUM:
			cout << "Medium";
			break;
		case GL_DEBUG_SEVERITY_HIGH:
			cout << "High";
			break;
	}
	cout << endl;
}
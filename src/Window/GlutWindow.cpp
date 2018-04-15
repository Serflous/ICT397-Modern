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

int GlutWindow::InitializeGlutWindow(int * argc, char ** argv)
{
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(INIT_WINDOW_POS_X, INIT_WINDOW_POS_Y);
	glutInitWindowSize(INIT_WINDOW_SIZE_X, INIT_WINDOW_SIZE_Y);
	m_winX = INIT_WINDOW_SIZE_X;
	m_winY = INIT_WINDOW_SIZE_Y;
	glutCreateWindow(WINDOW_TITLE);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		std::cerr << "Glew error: " << glewGetErrorString(err) << std::endl;
	}

	glutDisplayFunc(StaticDrawCallback);
	glutIdleFunc(StaticDrawCallback);
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
	if (InputManager::GetInstance()->GetKeyState('k') == KS_KEY_PRESSED)
	{
		m_wireframe = !m_wireframe;
		if(m_wireframe)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	if (InputManager::GetInstance()->GetKeyState('x') == KS_KEY_PRESSED)
	{
		glutExit();
	}
	m_scene->RenderScene();

	glutSwapBuffers();
}

void GlutWindow::ReshapeCallback(int w, int h)
{
	glViewport(0, 0, w, h);
	m_winX = w;
	m_winY = h;
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

void GlutWindow::StaticMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
	using namespace std;
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
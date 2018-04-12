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
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); // Initialize display modes, with RGBA, double buffering, and a depth buffer.
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
	glDebugMessageCallback(GLMessageCallback, nullptr);
	glDebugMessageControl(
		GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, true
	);
	return 0;
}

void GlutWindow::DrawCallback()
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	if (InputManager::GetInstance()->GetKeyState(']') == KS_KEY_PRESSED)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	if (InputManager::GetInstance()->GetKeyState('\'') == KS_KEY_PRESSED)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	m_scene->RenderScene();

	glutSwapBuffers();
}

void GlutWindow::ReshapeCallback(int w, int h)
{
	//float aspectRatio = w / h;

	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	glViewport(0, 0, w, h);
	//gluPerspective(45, aspectRatio, 0.1f, 10000);
	//glMatrixMode(GL_MODELVIEW);
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

void GlutWindow::GLMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
	using namespace std;
	cout << endl;
	cout << "Message: " << message << endl;
	cout << "Type: ";
	switch (type) {
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
	switch (severity) {
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
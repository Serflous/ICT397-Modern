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
#include "../Util/IniLoader.h"

class Scene;

	/**
	 * The GlutWindow is a singleton class responsible for creating and initializing the Glut window and providing the callbacks for glut to function
	 */
class GlutWindow
{
public:
		/**
		 * Returns the pointer to the instance of GlutWindow. If the instance hasn't been created yet, it will be created before being returned.
		 * @return GlutWindow* The pointer to the instance.
		 */
	static GlutWindow * GetInstance();

		/**
		 * Initializes the Glut window. Takes the input arguments from the main entry point as parameters.
		 * @param[in] argc The first entry point parameter
		 * @param[in] argv The second entry point parameter
		 */
	int InitializeGlutWindow(int * argc, char ** argv, IniLoader loader);
		/**
		 * Begins the main game loop with the specified scene as the initial scene.
		 * @param[in] scene The scene to begin with.
		 */
	void BeginMainGameLoop(Scene * scene);
		/**
		 * Internal callback. Will get called every time the screen is refreshed and requires redrawing.
		 */
	void DrawCallback();
		/**
		 * Internal callback. Will be called when the game screen is resized. This will also happen once at creation.
		 */
	void ReshapeCallback(int w, int h);
		/**
		* Update method. Is called on a timer, using gluts timer function. Will try to keep at 16ms.
		* @param[in] value The value that is passed through the glut timer. In this case it is the total time since the last update.
		*/
	void Update(int value);
		/**
		 * Gets the current window size.
		 * @param[out] x The width of the screen.
		 * @param[out] y The height of the screen.
		 */
	void GetWindowSize(int & x, int & y);

		/**
		 * FreeGlut callback. A static function provided to glut to call when the screen needs to be redrawn. Will call the internal DrawCallback.
		 */
	static void StaticDrawCallback();
		/**
		 * FreeGlut callback. A static function provided to glut to call when the screen has been resized. Will call the internal ReshapeCallback.
		 * @param[in] w The width of the screen
		 * @param[in] h The height of the screen
		 */
	static void StaticReshapeCallback(int w, int h);
		/**
		 * FreeGlut callback. A static function provided to glut to call when one of the character keys are pressed.
		 * @param[in] key The key that triggered the event
		 * @param[in] x The mouses x coordinates when the key was pressed.
		 * @param[in] y The mouses y coordinates when the key was pressed.
		 */
	static void StaticKeyboardCallback(unsigned char key, int x, int y);
		/**
		 * FreeGlut callback. A static function provided to glut to call when one of the character keys are released.
		 * @param[in] key The key that triggered the event
		 * @param[in] x The mouses x coordinates when the key was pressed.
		 * @param[in] y The mouses y coordinates when the key was pressed.
		 */
	static void StaticKeyboardUpCallback(unsigned char key, int x, int y);
		/**
		 * FreeGlut callback. A static function provided to glut to call when one of the special keys is pressed.
		 * @param[in] key The key that triggered the event
		 * @param[in] x The mouses x coordinates when the key was pressed.
		 * @param[in] y The mouses y coordinates when the key was pressed.
		 */
	static void StaticSpecialKeyboardCallback(int key, int x, int y);
		/**
		 * FreeGlut callback. A static function provided to glut to call when one of the special keys is released.
		 * @param[in] key The key that triggered the event
		 * @param[in] x The mouses x coordinates when the key was pressed.
		 * @param[in] y The mouses y coordinates when the key was pressed.
		 */
	static void StaticSpecialKeyboardUpCallback(int key, int x, int y);
		/**
		 * FreeGLut callback. A static function provided to glut to call when the mouse button has been clicked.
		 * @param[in] button The mouse button that was pressed.
		 * @param[in] state The state of the mouse button
		 * @param[in] x The mouses x coordinates.
		 * @param[in] y The mouses y coordinates.
		 */
	static void StaticMouseCallback(int button, int state, int x, int y);
		/**
		 * FreeGlut callback. A static function provided to glut to call when the mouses position is changed
		 * @param[in] x The mouses x coordinates.
		 * @param[in] y The mouses y coordinates.
		 */
	static void StaticMousePositionCallback(int x, int y);
		/**
		* FreeGlut callback. A static function provided to glut to call when the timer ticks.
		* @param[in] value The value suppied for the timer.
		*/
	static void StaticUpdateCallback(int value);

		/**
		 * FreeGlut callback. A static function provided to glut to call when GL has a debug message. Will display this message to the console.
		 * @param[in] source The source of the error.
		 * @param[in] type The type of the error.
		 * @param[in] id The id of the error.
		 * @param[in] severity The severity of the error.
		 * @param[in] length The length of the error.
		 * @param[in] message The message generated by ogl.
		 * @param[in] userParam Array pointer passed through from the debug registration call.
		 */
	static void APIENTRY StaticMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
private:
		/**
		 * Constructor
		 */
	GlutWindow();
		/**
		 * Destructor
		 */
	~GlutWindow();
		/**
		 * Copy Constructor
		 */
	GlutWindow(const GlutWindow & other);
private:

	Scene * m_scene;
	int m_winX, m_winY;

	bool m_wireframe = false;

	static GlutWindow * m_instance;
};
#endif
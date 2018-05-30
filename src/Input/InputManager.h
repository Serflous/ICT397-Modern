#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <iostream>
#include <GL/freeglut.h>

enum KeyState
{
	KS_KEY_PRESSED,
	KS_KEY_REPEAT,
	KS_KEY_RELEASED
};

enum ButtonState
{
	BS_BUTTON_CLICK,
	BS_BUTTON_DOWN,
	BS_BUTTON_UP
};

	/**
	 * Singleton class for capturing input from the user.
	 */
class InputManager
{
public:
		/**
		 * Gets the singelton instance. If it's not created yet, it will be created.
		 * @return InputManager* Gets the instance of the singleton object.
		 */
	static InputManager * GetInstance();

		/**
		* Gets the keystate of the specified key.
		* @param[in] int The key
		* @return KeyState The keystate of the key
		*/
	KeyState GetKeyState(int key);
		/**
		 * Gets the current mouse position.
		 * @param[out] x The x position of the mouse.
		 * @param[out] y The y position of the mouse.
		 */
	void GetMousePosition(int & x, int & y);
		/**
		 * Gets the state of the mouse button.
		 * @param[in] button The button of the mouse.
		 * @return ButtonState The state of the button
		 */
	ButtonState GetButtonState(int button);
	
		/**
		 * The internal callback. Called when a key is pressed or released.
		 * @param[in] key The key that triggered the event.
		 * @param[in] pressed A boolean value, true if the key is down, false if not.
		 */
	void KeyCallback(int key, bool pressed);
		/**
		 * The internal callback. Called when a mouse button is pressed.
		 * @param[in] button The button of the mouse.
		 * @param[in] state The state of the mouse button.
		 * @param[in] x The x position of the mouse pointer.
		 * @param[in] y The y position of the mouse pointer.
		 */
	void MouseCallback(int button, int state, int x, int y);
		/**
		 * The internal callback. Called when the mouses position has changed.
		 * @param[in] x The x position of the mouse pointer.
		 * @param[in] y The y position of the mouse pointer.
		 */
	void MouseMotionCallback(int x, int y);

private:
		/**
		 * Constructor
		 */
	InputManager();
		/**
		 * Destructor
		 */
	~InputManager();
		/**
		 * Copy constructor
		 */
	InputManager(const InputManager & other);

private:
	static InputManager * m_instance;

	KeyState m_keys[550];
	KeyState m_prevKeys[550];
	int m_x, m_y;
	ButtonState m_buttonState[3];
	ButtonState m_prevButtonState[3];
};

#endif
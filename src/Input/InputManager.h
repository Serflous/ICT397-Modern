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
	BS_BUTTON_DOWN,
	BS_BUTTON_UP
};

class InputManager
{
public:
	static InputManager * GetInstance();

	KeyState GetKeyState(int key);
	void GetMousePosition(int & x, int & y);
	ButtonState GetButtonState(int button);

	void KeyCallback(int key, bool pressed);
	void MouseCallback(int button, int state, int x, int y);
	void MouseMotionCallback(int x, int y);

private:
	InputManager();
	~InputManager();
	InputManager(const InputManager & other);

private:
	static InputManager * m_instance;

	KeyState m_keys[550];
	int m_x, m_y;
	ButtonState m_buttonState[3];
};

#endif
#include "InputManager.h"

InputManager * InputManager::m_instance;

InputManager * InputManager::GetInstance()
{
	if (!m_instance)
	{
		m_instance = new InputManager();
	}
	return m_instance;
}

InputManager::InputManager()
{
	for (int i = 0; i < 550; i++)
	{
		m_keys[i] = KS_KEY_RELEASED;
		m_prevKeys[i] = KS_KEY_RELEASED;
	}
	for (int i = 0; i < 3; i++)
	{
		m_buttonState[i] = BS_BUTTON_UP;
		m_prevButtonState[i] = BS_BUTTON_UP;
	}
}

InputManager::~InputManager()
{

}

InputManager::InputManager(const InputManager & other)
{

}

KeyState InputManager::GetKeyState(int key)
{

	if (m_prevKeys[key] == KS_KEY_PRESSED)
		m_keys[key] = KS_KEY_REPEAT;
	m_prevKeys[key] = m_keys[key];
	return m_keys[key];

}

void InputManager::KeyCallback(int key, bool press)
{
	m_keys[key] = press ? KS_KEY_PRESSED : KS_KEY_RELEASED;
}

void InputManager::MouseCallback(int button, int state, int x, int y)
{
	m_x = x;
	m_y = y;
	m_buttonState[button] = state == GLUT_DOWN ? BS_BUTTON_CLICK : BS_BUTTON_UP;

}

void InputManager::MouseMotionCallback(int x, int y)
{
	m_x = x;
	m_y = y;
}

void InputManager::GetMousePosition(int & x, int & y)
{
	x = m_x;
	y = m_y;
}

ButtonState InputManager::GetButtonState(int button)
{
	if (m_prevButtonState[button] == BS_BUTTON_CLICK)
		m_buttonState[button] = BS_BUTTON_DOWN;
	m_prevButtonState[button] = m_buttonState[button];
	return m_buttonState[button];
}
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
	}
	for (int i = 0; i < 3; i++)
	{
		m_buttonState[i] = BS_BUTTON_UP;
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

	return m_keys[key];

}

void InputManager::KeyCallback(int key, bool press)
{
	m_keys[key] = press ? KS_KEY_PRESSED : KS_KEY_RELEASED;
}

void InputManager::MouseCallback(int button, int state, int x, int y)
{
	//m_deltaX = m_x - x;
	//m_deltaY = m_y - y;
	m_x = x;
	m_y = y;
	m_buttonState[button] = state == GLUT_DOWN ? BS_BUTTON_DOWN : BS_BUTTON_UP;

}

void InputManager::MouseMotionCallback(int x, int y)
{
	//m_deltaX = m_x - x;
	//m_deltaY = m_y - y;
	m_x = x;
	m_y = y;
	//std::cout << "DeltaX: " << m_deltaX << " DeltaY: " << m_deltaY << std::endl;
}

void InputManager::GetMousePosition(int & x, int & y)
{
	x = m_x;
	y = m_y;
}

ButtonState InputManager::GetButtonState(int button)
{
	return m_buttonState[button];
}
#include "Camera.h"

Camera::Camera(int x, int y, int z)
{
	m_pitch = 0;
	m_roll = 0;
	m_yaw = 0;
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
	InputManager::GetInstance()->GetMousePosition(m_lastMouseX, m_lastMouseY);
}

Camera::Camera(const Camera & other)
{

}

Camera::~Camera()
{

}

glm::vec3 Camera::GetPosition()
{
	return m_position;
}

float Camera::GetPitch()
{
	return m_pitch;
}

float Camera::GetRoll()
{
	return m_roll;
}

float Camera::GetYaw()
{
	return m_yaw;
}

void Camera::Move()
{
	int mouseX, mouseY;
	int winX, winY;

	GlutWindow::GetInstance()->GetWindowSize(winX, winY);

	InputManager::GetInstance()->GetMousePosition(mouseX, mouseY);
	int deltaX = mouseX - (winX / 2);
	int deltaY = mouseY - (winY / 2);

	m_yaw += deltaX * m_rotSpeed;
	m_pitch += deltaY * m_rotSpeed;

	if (m_yaw > 360)
		m_yaw = 0;
	if (m_yaw < 0)
		m_yaw = 360;
	if (m_pitch > 90)
		m_pitch = 90;
	if (m_pitch < -90)
		m_pitch = -90;
	glutWarpPointer(winX / 2, winY / 2);

	if (InputManager::GetInstance()->GetKeyState('w') == KS_KEY_PRESSED)
	{
		m_position.x += (float)(sin(glm::radians(m_yaw))) * m_speed;
		m_position.z -= (float)(cos(glm::radians(m_yaw))) * m_speed;
	}
	if (InputManager::GetInstance()->GetKeyState('s') == KS_KEY_PRESSED)
	{
		m_position.x -= (float)(sin(glm::radians(m_yaw))) * m_speed;
		m_position.z += (float)(cos(glm::radians(m_yaw))) * m_speed;
	}
	if (InputManager::GetInstance()->GetKeyState('a') == KS_KEY_PRESSED)
	{
		m_position.x -= (float)(cos(glm::radians(m_yaw))) * m_speed;
		m_position.z -= (float)(sin(glm::radians(m_yaw))) * m_speed;
	}
	if (InputManager::GetInstance()->GetKeyState('d') == KS_KEY_PRESSED)
	{
		m_position.x += (float)(cos(glm::radians(m_yaw))) * m_speed;
		m_position.z += (float)(sin(glm::radians(m_yaw))) * m_speed;
	}
	
	if (InputManager::GetInstance()->GetKeyState(' ') == KS_KEY_PRESSED)
	{
		m_position.y += m_speed;
	}
	if (InputManager::GetInstance()->GetKeyState('x') == KS_KEY_PRESSED)
	{
		m_position.y -= m_speed;
	}
}

void Camera::SetHeight(float height)
{
	m_position.y = height;
}

float Camera::GetCamViewHeight()
{
	return m_camViewHeight;
}
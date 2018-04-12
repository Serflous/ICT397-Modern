#include "Camera.h"

Camera::Camera()
{
	m_pitch = 0;
	m_roll = 0;
	m_yaw = 0;
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
	if (InputManager::GetInstance()->GetKeyState('w') == KS_KEY_PRESSED)
	{
		m_position.z -= m_speed;
	}
	if (InputManager::GetInstance()->GetKeyState('s') == KS_KEY_PRESSED)
	{
		m_position.z += m_speed;
	}
	if (InputManager::GetInstance()->GetKeyState('a') == KS_KEY_PRESSED)
	{
		m_position.x -= m_speed;
	}
	if (InputManager::GetInstance()->GetKeyState('d') == KS_KEY_PRESSED)
	{
		m_position.x += m_speed;
	}
}
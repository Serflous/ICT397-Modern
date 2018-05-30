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

void Camera::Move(std::vector<AABB> boxes, int deltaTime)
{
	int mouseX, mouseY;
	int winX, winY;

	GlutWindow::GetInstance()->GetWindowSize(winX, winY);

	InputManager::GetInstance()->GetMousePosition(mouseX, mouseY);
	int deltaX = mouseX - (winX / 2);
	int deltaY = mouseY - (winY / 2);

	m_yaw += deltaX * m_rotSpeed * deltaTime;
	m_pitch += deltaY * m_rotSpeed * deltaTime;

	if (m_yaw > 360)
		m_yaw = 0;
	if (m_yaw < 0)
		m_yaw = 360;
	if (m_pitch > 90)
		m_pitch = 90;
	if (m_pitch < -90)
		m_pitch = -90;
	glutWarpPointer(winX / 2, winY / 2);

	glm::vec3 nextPosition = m_position;

	if (InputManager::GetInstance()->GetKeyState('w') == KS_KEY_PRESSED || InputManager::GetInstance()->GetKeyState('w') == KS_KEY_REPEAT)
	{
		nextPosition.x += (float)(sin(glm::radians(m_yaw))) * m_speed * deltaTime;
		nextPosition.z -= (float)(cos(glm::radians(m_yaw))) * m_speed * deltaTime;
	}
	if (InputManager::GetInstance()->GetKeyState('s') == KS_KEY_PRESSED || InputManager::GetInstance()->GetKeyState('s') == KS_KEY_REPEAT)
	{
		nextPosition.x -= (float)(sin(glm::radians(m_yaw))) * m_speed * deltaTime;
		nextPosition.z += (float)(cos(glm::radians(m_yaw))) * m_speed * deltaTime;
	}
	if (InputManager::GetInstance()->GetKeyState('a') == KS_KEY_PRESSED || InputManager::GetInstance()->GetKeyState('a') == KS_KEY_REPEAT)
	{
		nextPosition.x -= (float)(cos(glm::radians(m_yaw))) * m_speed * deltaTime;
		nextPosition.z -= (float)(sin(glm::radians(m_yaw))) * m_speed * deltaTime;
	}
	if (InputManager::GetInstance()->GetKeyState('d') == KS_KEY_PRESSED || InputManager::GetInstance()->GetKeyState('d') == KS_KEY_REPEAT)
	{
		nextPosition.x += (float)(cos(glm::radians(m_yaw))) * m_speed * deltaTime;
		nextPosition.z += (float)(sin(glm::radians(m_yaw))) * m_speed * deltaTime;
	}

	bool hasCollided = false;
	AABB myBox;
	myBox.SetLocalCoordinates(nextPosition);
	myBox.SetMin(glm::vec3(-0.5f, -0.5f, -0.5f));
	myBox.SetMax(glm::vec3(0.5f, 0.5f, 0.5f));
	std::vector<AABB>::iterator iter;
	for (iter = boxes.begin(); iter != boxes.end(); iter++)
	{
		AABB box = (*iter);
		if (myBox.IsColliding(box))
		{
			hasCollided = true;
			break;
		}
	}

	if(!hasCollided)
		m_position = nextPosition;

	if (InputManager::GetInstance()->GetKeyState(' ') == KS_KEY_PRESSED)
	{
		std::cout << "Cam Position;" << std::endl;
		std::cout << "X: " << m_position.x << std::endl;
		std::cout << "Y: " << m_position.y << std::endl;
		std::cout << "Z: " << m_position.z << std::endl << std::endl;
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
#ifndef CAMERA_H
#define CAMERA_H

#include <glm/vec3.hpp>
#include <GL/glew.h>

#include "../Input/InputManager.h"

class Camera
{
public:
	Camera();
	Camera(const Camera & other);
	~Camera();

	glm::vec3 GetPosition();
	float GetPitch();
	float GetYaw();
	float GetRoll();

	void Move();
private:

private:
	glm::vec3 m_position;
	float m_pitch, m_yaw, m_roll;
	float m_speed = 0.1f;
};

#endif
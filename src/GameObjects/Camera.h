#ifndef CAMERA_H
#define CAMERA_H

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <vector>

#include "../Window/GlutWindow.h"
#include "../Input/InputManager.h"
#include "../Collision/AABB.h"

	/**
	 * The camera holds information about what the user sees.
	 * @todo Make base class and extend to first person camera, third person camera, and top down camera.
	 */
class Camera
{
public:
		/**
		 * Constructor
		 * @param[in] x The x position of the camera
		 * @param[in] y The y position of the camera
		 * @param[in] z The z position of the camera.
		 */
	Camera(int x, int y, int z);
		/**
		 * The copy constructor
		 */
	Camera(const Camera & other);
		/**
		 * Destructor
		 */
	~Camera();

		/**
		 * Gets the position of the camera
		 * @return glm::vec3 The position of the camera.
		 */
	glm::vec3 GetPosition();
		/**
		 * Gets the pitch of the camera.
		 * @return float The pitch of the camera.
		 */
	float GetPitch();
		/**
		 * Gets the yaw of the camera.
		 * @return float The yaw of the camera.
		 */
	float GetYaw();
		/**
		 * Gets the roll of the camera.
		 * @return floar The roll of the camera.
		 */
	float GetRoll();
		/**
		 * Gets the camera view height.
		 * @return float The height of the camera view.
		 * @todo Calculate the camera view based in the projection matrix
		 */
	float GetCamViewHeight();

		/**
		 * Moves the camera based on what keys are currently pressed and the delta location of the mouse. Also performs collision detection.
		 * @param[in] boxes A list of bounding boxes.
		 * @todo Move collision detection to its own class.
		 */
	void Move(std::vector<AABB> boxes, int deltaTime);
		/**
		 * Sets the y coordinate of the camera.
		 * @param[in] height The height to set the camera to.
		 */
	void SetHeight(float height);
private:

private:
	glm::vec3 m_position;
	float m_pitch, m_yaw, m_roll;
	float m_speed = 0.018f;
	float m_rotSpeed = 0.006f;
	int m_lastMouseX = 0, m_lastMouseY = 0;
	const float m_camViewHeight = 2;
};

#endif
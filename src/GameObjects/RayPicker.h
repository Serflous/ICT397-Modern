#ifndef RAYPICKER_H
#define RAYPICKER_H

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <stdio.h>
#include <iostream>

#include "Camera.h"

class Camera;

class RayPicker
{
public:
	RayPicker(glm::mat4x4 projectionMatrix);
	RayPicker(const RayPicker & other);
	~RayPicker();

	glm::vec3 GetRay();
	
	void Update(Camera * camera);

private:
private:
	glm::mat4x4 m_projectionMatrix;
	Camera * m_camera;
	glm::vec3 m_ray;
};

#endif
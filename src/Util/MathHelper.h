#ifndef MATHHELPER_H
#define MATHHELPER_H

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include "../GameObjects/Camera.h"

class Camera;

class MathHelper
{
public:
	static glm::mat4x4 CreateTransformationMatrix(glm::vec3 translation, float rx, float ry, float rz, float scale);
	static glm::mat4x4 CreateViewMatrix(Camera * cam);
};

#endif
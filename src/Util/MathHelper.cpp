#include "MathHelper.h"

glm::mat4x4 MathHelper::CreateTransformationMatrix(glm::vec3 translation, float rx, float ry, float rz, glm::vec3 scale)
{
	glm::mat4x4 transformationMatrix(1.0f);
	transformationMatrix = glm::translate(transformationMatrix, translation);
	transformationMatrix = glm::rotate(transformationMatrix, glm::radians(rx), glm::vec3(1, 0, 0));
	transformationMatrix = glm::rotate(transformationMatrix, glm::radians(ry), glm::vec3(0, 1, 0));
	transformationMatrix = glm::rotate(transformationMatrix, glm::radians(rz), glm::vec3(0, 0, 1));
	transformationMatrix = glm::scale(transformationMatrix, scale);
	return transformationMatrix;
}

glm::mat4x4 MathHelper::CreateViewMatrix(Camera * cam)
{
	glm::mat4x4 viewMatrix(1.0f);
	viewMatrix = glm::rotate(viewMatrix, glm::radians(cam->GetPitch()), glm::vec3(1, 0, 0));
	viewMatrix = glm::rotate(viewMatrix, glm::radians(cam->GetYaw()), glm::vec3(0, 1, 0));
	glm::vec3 camPos = cam->GetPosition();
	glm::vec3 negCamPos(-camPos.x, -camPos.y, -camPos.z);
	viewMatrix = glm::translate(viewMatrix, negCamPos);
	return viewMatrix;
}

bool MathHelper::IsInteger(float num)
{
	return std::floor(num) == num;
}
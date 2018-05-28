#include "MathHelper.h"

glm::mat4x4 MathHelper::CreateTransformationMatrix(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale)
{
	glm::mat4x4 transformationMatrix(1.0f);
	transformationMatrix = glm::translate(transformationMatrix, translation);
	transformationMatrix = glm::rotate(transformationMatrix, glm::radians(rotation.x), glm::vec3(1, 0, 0));
	transformationMatrix = glm::rotate(transformationMatrix, glm::radians(rotation.y), glm::vec3(0, 1, 0));
	transformationMatrix = glm::rotate(transformationMatrix, glm::radians(rotation.z), glm::vec3(0, 0, 1));
	transformationMatrix = glm::scale(transformationMatrix, scale);
	return transformationMatrix;
}

glm::mat4x4 MathHelper::CreateTransformationMatrix(glm::vec2 translation, glm::vec2 rotation, glm::vec2 scale)
{
	glm::vec3 translation3(translation, 0.0);
	glm::vec3 rotation3(rotation, 0.0);
	glm::vec3 scale3(scale, 0.0);
	return CreateTransformationMatrix(translation3, rotation3, scale3);
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
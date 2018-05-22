#include "BoneTransform.h"

BoneTransform::BoneTransform()
{

}

BoneTransform::BoneTransform(glm::vec3 position, glm::quat rotation)
{
	m_position = position;
	m_rotation = rotation;
}

BoneTransform::BoneTransform(const BoneTransform & other)
{

}

BoneTransform::~BoneTransform()
{

}

glm::mat4x4 BoneTransform::GetLocalTransform()
{
	glm::mat4x4 transform;
	glm::mat4x4 rotationMatrix = glm::toMat4(m_rotation);
	transform = glm::translate(transform, m_position);
	transform *= rotationMatrix;
	return transform;
}

BoneTransform * BoneTransform::Lerp(BoneTransform * a, BoneTransform * b, float progression)
{
	glm::vec3 position = Lerp(a->m_position, b->m_position, progression);
	glm::quat rotation = Lerp(a->m_rotation, b->m_rotation, progression);
	return new BoneTransform(position, rotation);
}

glm::vec3 BoneTransform::Lerp(glm::vec3 start, glm::vec3 end, float progression)
{
	float x = start.x + (end.x - start.x) * progression;
	float y = start.y + (end.y - start.y) * progression;
	float z = start.z + (end.z - start.z) * progression;
	glm::vec3 result(x, y, z);
	return result;
}

glm::quat BoneTransform::Lerp(glm::quat a, glm::quat b, float progression)
{
	glm::quat result;
	float dotProduct = glm::dot(a, b);
	float inverseProgression = 1 - progression;
	if (dotProduct >= 0)
	{
		result.w = inverseProgression * a.w + progression * b.w;
		result.x = inverseProgression * a.x + progression * b.x;
		result.y = inverseProgression * a.y + progression * b.y;
		result.z = inverseProgression * a.z + progression * b.z;
	}
	else
	{
		result.w = inverseProgression * a.w + progression * -b.w;
		result.x = inverseProgression * a.x + progression * -b.x;
		result.y = inverseProgression * a.y + progression * -b.y;
		result.z = inverseProgression * a.z + progression * -b.z;
	}
	result = glm::normalize(result);
	return result;
}
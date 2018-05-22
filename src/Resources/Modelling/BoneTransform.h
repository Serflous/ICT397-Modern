#ifndef BONETRANSFORM_H
#define BONETRANSFORM_H

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>

class BoneTransform
{
public:
	BoneTransform();
	BoneTransform(glm::vec3 position, glm::quat rotation);
	BoneTransform(const BoneTransform & other);
	~BoneTransform();

	glm::mat4x4 GetLocalTransform();

	static BoneTransform * Lerp(BoneTransform * a, BoneTransform * b, float progression);
	static glm::quat Lerp(glm::quat a, glm::quat b, float progression);

private:
	static glm::vec3 Lerp(glm::vec3 start, glm::vec3 end, float progression);
private:
	glm::vec3 m_position;
	glm::quat m_rotation;
};

#endif
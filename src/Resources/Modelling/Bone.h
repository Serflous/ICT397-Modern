#ifndef BONE
#define BONE

#include <vector>
#include <glm/mat4x4.hpp>

class Bone
{
public:
	Bone(int id, const char * name, glm::mat4x4 transform);

	void AddBone(Bone * child);
	glm::mat4x4 GetAnimatedTransform();
	glm::mat4x4 GetLocalTransformInverse();
	int GetIndex();
	std::vector<Bone*> GetChildBones();

	void SetAnimatedTransform(glm::mat4x4 transform);
	void CalculateInverse(glm::mat4x4 parentMatrix);
private:

private:
	int m_idx;
	const char * m_name;
	std::vector<Bone*> m_bones;
	// Transforms
	glm::mat4x4 m_animatedTransform;
	glm::mat4x4 m_localTransform;
	glm::mat4x4 m_localTransformInverse;
};

#endif
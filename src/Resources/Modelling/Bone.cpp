#include "Bone.h"

Bone::Bone(int idx, const char * name, glm::mat4x4 transform)
{
	m_idx = idx;
	m_name = name;
	m_localTransform = transform;
}

void Bone::AddBone(Bone * child)
{
	m_bones.push_back(child);
}

glm::mat4x4 Bone::GetAnimatedTransform()
{
	return m_animatedTransform;
}

glm::mat4x4 Bone::GetLocalTransformInverse()
{
	return m_localTransformInverse;
}

int Bone::GetIndex()
{
	return m_idx;
}

std::vector<Bone*> Bone::GetChildBones()
{
	return m_bones;
}

const char * Bone::GetName()
{
	return m_name;
}

void Bone::SetAnimatedTransform(glm::mat4x4 transform)
{
	m_animatedTransform = transform;
}

void Bone::CalculateInverse(glm::mat4x4 parentMatrix)
{
	glm::mat4x4 localTransform = parentMatrix * m_localTransform;
	m_localTransformInverse = glm::inverse(localTransform);
	std::vector<Bone*>::iterator childIter;
	for (childIter = m_bones.begin(); childIter != m_bones.end(); childIter++)
	{
		(*childIter)->CalculateInverse(localTransform);
	}
}
#include "ModelAnimated.h"

ModelAnimated::ModelAnimated(int vaoId, int vertexCount, Bone * rootBone, int boneCount)
{
	m_vaoId = vaoId;
	m_vertexCount = vertexCount;
	m_rootBone = rootBone;
	m_boneCount = boneCount;
	glm::mat4x4 identity(1.0);
	//rootBone->CalculateInverse(identity);
}

Bone * ModelAnimated::GetRootBone()
{
	return m_rootBone;
}

// Animate

// Update

glm::mat4x4 ModelAnimated::GetBoneTransforms()
{
	glm::mat4x4 * transforms = new glm::mat4x4[m_boneCount];
	CreateBoneList(m_rootBone, transforms);
	return *transforms;
}

void ModelAnimated::CreateBoneList(Bone * root, glm::mat4x4 * transforms)
{
	transforms[root->GetIndex()] = root->GetAnimatedTransform();
	std::vector<Bone*>::iterator boneIter;
	for (boneIter = root->GetChildBones().begin(); boneIter != root->GetChildBones().end(); boneIter++)
	{
		CreateBoneList((*boneIter), transforms);
	}
}
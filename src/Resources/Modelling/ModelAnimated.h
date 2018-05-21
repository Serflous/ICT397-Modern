#ifndef MODELANIMATED_H
#define MODELANIMATED_H

#include "ModelBase.h"
#include "Bone.h"

class ModelAnimated : public ModelBase
{
public:
	ModelAnimated(int vaoId, int vertexCount, Bone * rootBone, int boneCount);

	Bone * GetRootBone();
	//void Animate();
	//void Update();
	glm::mat4x4 GetBoneTransforms();
private:
	void CreateBoneList(Bone * root, glm::mat4x4 * transforms);
private:
	Bone * m_rootBone;
	int m_boneCount;
	// Animator
};

#endif
#ifndef MODELANIMATED_H
#define MODELANIMATED_H

#include "ModelBase.h"
#include "Bone.h"

	/**
	* Describes the information used in an animated model
	*/
class ModelAnimated : public ModelBase
{
public:
		/**
		* Constructor.
		* @param[in] vaoId The ID of the VAO
		* @param[in] vertexCount The count of verts.
		* @param[in] rootBone The root bone in the animated model
		* @param[in] boneCount The number of bones in the model
		*/
	ModelAnimated(int vaoId, int vertexCount, Bone * rootBone, int boneCount);

		/**
		* Gets the root bone used by the model
		*/
	Bone * GetRootBone();
	//void Animate();
	//void Update();
		/**
		* Gets the bones transform matrix
		* @return glm::mat4x4 The transforms of the bone.
		*/
	glm::mat4x4 GetBoneTransforms();
private:
		/**
		* Creates a list of bones from the root bone.
		* @param[in] root The root bone.
		* @param[in] transforms The transforms used by the bone
		*/
	void CreateBoneList(Bone * root, glm::mat4x4 * transforms);
private:
	Bone * m_rootBone;
	int m_boneCount;
	// Animator
};

#endif
#ifndef BONE
#define BONE

#include <vector>
#include <glm/mat4x4.hpp>

	/**
	* Contains information about a Bone
	*/
class Bone
{
public:
		/**
		* Constructor.
		* @param[in] id The index of the bone.
		* @param[in] name The name of the bone.
		* @param[in] transform The transform of the bone.
		*/
	Bone(int id, const char * name, glm::mat4x4 transform);

		/**
		* Adds a bone as a child to this bone.
		* @param[in] child The child bone.
		*/
	void AddBone(Bone * child);
		/**
		* Gets the animated transformation matrix.
		* @return glm::mat4x4 The animated transform.
		*/
	glm::mat4x4 GetAnimatedTransform();
		/**
		* Gets the inverse of the local transfomration matrix.
		* @return glm::mat4x4 The transformation matrix.
		*/
	glm::mat4x4 GetLocalTransformInverse();
		/**
		* Gets the index of the bone.
		* @return int The index of the bone
		*/
	int GetIndex();
		/**
		* Gets a list of all the child bones.
		* @return std::vector<Bone*> The child bones.
		*/
	std::vector<Bone*> GetChildBones();
		/**
		* Gets the name of the bone.
		*/
	const char * GetName();

		/**
		* Sets the animated transformation matrix.
		* @param[in] transform The transform.
		*/
	void SetAnimatedTransform(glm::mat4x4 transform);
		/**
		* Calculate the inverse matrix from the parent matrix.
		* @param[in] parentMatrix The parent matrix to inverse.
		*/
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
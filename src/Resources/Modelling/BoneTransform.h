#ifndef BONETRANSFORM_H
#define BONETRANSFORM_H

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>

	/**
	* Represents the Boen Transformation data. Used in animation
	*/
class BoneTransform
{
public:
		/**
		* Default constructor
		*/
	BoneTransform();
		/**
		* Constructor. Takes a position and a rotation.
		* @param[in] position The position of the bone.
		* @param[in] rotation The rotation of the bone.
		*/
	BoneTransform(glm::vec3 position, glm::quat rotation);
		/**
		* Default constructor
		*/
	BoneTransform(const BoneTransform & other);
		/**
		* Default destructor
		*/
	~BoneTransform();

		/**
		* Gets the local transformation matrix of the bone.
		* @return glm::mat4x4 The transformation matrix.
		*/
	glm::mat4x4 GetLocalTransform();

		/**
		* Linear Interpolation between 2 bone transforms.
		* @param[in] a The first bone transform.
		* @param[in] b The second bone transform.
		* @param[in] progression The value between 0 and 1.
		* @return The new Bone Transform.
		*/
	static BoneTransform * Lerp(BoneTransform * a, BoneTransform * b, float progression);
		/**
		* Linear Interpolation between 2 quaternions
		* @param[in] a The first quaternion
		* @param[in] b The second quaternion
		* @param[in] progression The progression value between 0 and 1.
		* @return glm::quaternion The new quaternion
		*/
	static glm::quat Lerp(glm::quat a, glm::quat b, float progression);

private:
		/**
		* Linear Interpolation been 2 vec3s.
		* @param[in] start The first vec3.
		* @param[in] end The second vec3.
		* @param[in] progression The progression value between 0 and 1.
		* @return glm::vec3 The new vec3.
		*/
	static glm::vec3 Lerp(glm::vec3 start, glm::vec3 end, float progression);
private:
	glm::vec3 m_position;
	glm::quat m_rotation;
};

#endif
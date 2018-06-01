#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "ModelAnimated.h"
#include "Animation.h"
#include "Bone.h"
#include "BoneTransform.h"

#include <map>
#include <vector>
#include <glm/mat4x4.hpp>

	/**
	* Modifies the bone with the animation and key frames.
	*/
class Animator
{
public:
		/**
		* Default constructor
		*/
	Animator();
		/**
		* Constructor.
		* @param[in] model The animated model.
		*/
	Animator(ModelAnimated * model);
		/**
		* Default copy constructor
		*/
	Animator(const Animator & other);
		/**
		* Default destructor
		*/
	~Animator();

		/**
		* Perform the animation.
		* @param[in] animation The animation to perform.
		*/
	void Animate(Animation * animation);
		/**
		* Update with the current delta time.
		* @param[in] deltaTime. The time passed since the last frame.
		*/
	void Update(int deltaTime);

private:
		/**
		* Gets the current pose in the animation.
		* @return std::map<const char *, glm::mat4x4> The pose.
		*/
	std::map<const char *, glm::mat4x4> GetCurrentPose();
		/**
		* Modifies the bones with the poses.
		* @param[in] pose The pose to modify the bone with
		* @param[in] bone The bone to modify.
		* @param[in] parent The parent matrix.
		*/
	void ModBoneWithPose(std::map<const char *, glm::mat4x4> pose, Bone * bone, glm::mat4x4 parent);
		/**
		* Gets the relative frames.
		* @return std::vector<KeyFrame*> The list of frames.
		*/
	std::vector<KeyFrame*> GetRelFrames();
		/**
		* Calculates the progression between the two frames as a float value.
		* @param[in] a The first frame.
		* @param[in] b The second frame.
		* @return float The progression
		*/
	float CalculateProgressionInFrames(KeyFrame * a, KeyFrame * b);
		/**
		* Linear Interpolate between the two frames.
		* @param[in] a The first key frame.
		* @param[in] b The second key frame.
		* @param[in] progression The progression between the two frames, between 0 and 1.
		* @return std::map<const char *, glm::mat4x4> The transform matrix.
		*/
	std::map<const char *, glm::mat4x4> Lerp(KeyFrame * a, KeyFrame * b, float progression);
private:
	ModelAnimated * m_model;
	Animation * m_animation;
	float m_totalTime;
};

#endif
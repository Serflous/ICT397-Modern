#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "ModelAnimated.h"
#include "Animation.h"
#include "Bone.h"
#include "BoneTransform.h"

#include <map>
#include <vector>
#include <glm/mat4x4.hpp>

class Animator
{
public:
	Animator();
	Animator(ModelAnimated * model);
	Animator(const Animator & other);
	~Animator();

	void Animate(Animation * animation);
	void Update(int deltaTime);

private:
	std::map<const char *, glm::mat4x4> GetCurrentPose();
	void ModBoneWithPose(std::map<const char *, glm::mat4x4> pose, Bone * bone, glm::mat4x4 parent);
	std::vector<KeyFrame*> GetRelFrames();
	float CalculateProgressionInFrames(KeyFrame * a, KeyFrame * b);
	std::map<const char *, glm::mat4x4> Lerp(KeyFrame * a, KeyFrame * b, float progression);
private:
	ModelAnimated * m_model;
	Animation * m_animation;
	float m_totalTime;
};

#endif
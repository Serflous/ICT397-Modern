#include "Animator.h"

Animator::Animator()
{
	m_animation = nullptr;
}

Animator::Animator(ModelAnimated * model)
{
	m_animation = nullptr;
	m_model = model;
}

Animator::Animator(const Animator & other)
{

}

Animator::~Animator()
{

}

void Animator::Animate(Animation * animation)
{
	m_totalTime = 0;
	m_animation = animation;
}

void Animator::Update(int deltaTime)
{
	if (m_animation == nullptr)
	{
		return;
	}
	m_totalTime += deltaTime;
	if (m_totalTime > m_animation->GetLength())
	{
		m_totalTime = fmod(m_totalTime, m_animation->GetLength());
	}
	std::map<const char *, glm::mat4x4> currentPose = GetCurrentPose();
	glm::mat4x4 mat(1.0f);
	ModBoneWithPose(currentPose, m_model->GetRootBone(), mat);
}

std::map<const char *, glm::mat4x4> Animator::GetCurrentPose()
{
	std::vector<KeyFrame*> frames = GetRelFrames();
	float progression = CalculateProgressionInFrames(frames[0], frames[1]);
	return Lerp(frames[0], frames[1], progression);
}

void Animator::ModBoneWithPose(std::map<const char *, glm::mat4x4> pose, Bone * bone, glm::mat4x4 parent)
{
	glm::mat4x4 localTransform = pose.at(bone->GetName());
	glm::mat4x4 transform = parent * localTransform;
	std::vector<Bone*>::iterator boneIter;
	for (boneIter = bone->GetChildBones().begin(); boneIter != bone->GetChildBones().end(); boneIter++)
	{
		ModBoneWithPose(pose, (*boneIter), transform);
	}
	transform *= bone->GetLocalTransformInverse();
	bone->SetAnimatedTransform(transform);
}

std::vector<KeyFrame*> Animator::GetRelFrames()
{
	std::vector<KeyFrame*> allFrames = m_animation->GetKeyFrames();
	std::vector<KeyFrame*> resultFrames;
	KeyFrame * previousFrame = allFrames[0];
	KeyFrame * nextFrame = allFrames[0];
	std::vector<KeyFrame*>::iterator frameIter;
	for (frameIter = allFrames.begin(); frameIter != allFrames.end(); frameIter++)
	{
		nextFrame = (*frameIter);
		if (nextFrame->GetTimestamp() > m_totalTime)
		{
			break;
		}
		previousFrame = nextFrame;
	}
	resultFrames.push_back(previousFrame);
	resultFrames.push_back(nextFrame);
	return resultFrames;
}

float Animator::CalculateProgressionInFrames(KeyFrame * a, KeyFrame * b)
{
	float totalTime = b->GetTimestamp() - a->GetTimestamp();
	float currentTime = m_totalTime - a->GetTimestamp();
	return currentTime / totalTime;
}

std::map<const char *, glm::mat4x4> Animator::Lerp(KeyFrame * a, KeyFrame * b, float progression)
{
	std::map<const char *, glm::mat4x4> pose;
	std::map<const char *, BoneTransform*>::iterator poseIter;
	for (poseIter = b->GetPoses().begin(); poseIter != b->GetPoses().end(); poseIter++)
	{
		BoneTransform * prev = b->GetPoses()[poseIter->first];
		BoneTransform * next = a->GetPoses()[poseIter->first];
		BoneTransform * current = BoneTransform::Lerp(prev, next, progression);
		pose[poseIter->first] = current->GetLocalTransform();
	}
	return pose;
}
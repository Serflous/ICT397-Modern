#ifndef KEYFRAME_H
#define KEYFRAME_H

#include <map>

#include "BoneTransform.h"

class KeyFrame
{
public:
	KeyFrame();
	KeyFrame(float timeStamp);
	KeyFrame(const KeyFrame & other);
	~KeyFrame();

	float GetTimestamp();
	std::map<const char *, BoneTransform*> GetPoses();
private:
	float m_timeStamp;
	std::map<const char *, BoneTransform*> m_poses;
};

#endif
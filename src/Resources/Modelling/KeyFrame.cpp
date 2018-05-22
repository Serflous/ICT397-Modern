#include "KeyFrame.h"

KeyFrame::KeyFrame()
{

}

KeyFrame::KeyFrame(float timeStamp)
{
	m_timeStamp = timeStamp;
}

KeyFrame::KeyFrame(const KeyFrame & other)
{

}

KeyFrame::~KeyFrame()
{

}

float KeyFrame::GetTimestamp()
{
	return m_timeStamp;
}

std::map<const char *, BoneTransform*> KeyFrame::GetPoses()
{
	return m_poses;
}
#include "Animation.h"

Animation::Animation()
{

}

Animation::Animation(float length)
{
	m_length = length;
}

Animation::Animation(const Animation & other)
{

}

Animation::~Animation()
{

}

float Animation::GetLength()
{
	return m_length;
}

std::vector<KeyFrame*> Animation::GetKeyFrames()
{
	return m_keyFrames;
}
#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>

#include "KeyFrame.h"

class Animation
{
public:
	Animation();
	Animation(float length);
	Animation(const Animation & other);
	~Animation();

	float GetLength();
	std::vector<KeyFrame*> GetKeyFrames();

private:
	float m_length;
	std::vector<KeyFrame*> m_keyFrames;
};

#endif
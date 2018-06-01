#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>

#include "KeyFrame.h"

	/**
	* Defines an animation and contains its keyframe.
	*/
class Animation
{
public:
		/**
		* Default constructor
		*/
	Animation();
		/**
		* Constructor.
		* @param[in] length The length of the animation.
		*/
	Animation(float length);
		/**
		* Default copy constructor
		*/
	Animation(const Animation & other);
		/**
		* Default destructor
		*/
	~Animation();

		/**
		* Gets the time length in the animation
		* @return float The length.
		*/
	float GetLength();
		/**
		* Gets the list of keyframes used by the animation.
		* @return std::vector<KeyFrame*> The list of key frames.
		*/
	std::vector<KeyFrame*> GetKeyFrames();

private:
	float m_length;
	std::vector<KeyFrame*> m_keyFrames;
};

#endif
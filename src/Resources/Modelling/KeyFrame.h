#ifndef KEYFRAME_H
#define KEYFRAME_H

#include <map>

#include "BoneTransform.h"

	/**
	* The key frame of each animation
	*/
class KeyFrame
{
public:
		/**
		* Default constructor
		*/
	KeyFrame();
		/**
		* Constructor. Takes in a time stamp of the key frame.
		* @param[in] timeStamp The timestamp of the keyframe.
		*/
	KeyFrame(float timeStamp);
		/**
		* Default copy constructor
		*/
	KeyFrame(const KeyFrame & other);
		/**
		* Default destructor
		*/
	~KeyFrame();

		/**
		* Gets the time stamp of the keyframe
		* @return float The timestamp of the keyframe.
		*/
	float GetTimestamp();
		/**
		* Gets the list of transforms in the pose.
		* @retunr std::map<const char *, BoneTransform> The transforms.
		*/
	std::map<const char *, BoneTransform*> GetPoses();
private:
	float m_timeStamp;
	std::map<const char *, BoneTransform*> m_poses;
};

#endif
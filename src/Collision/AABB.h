#ifndef AABB_H
#define AABB_H

#include <glm/vec3.hpp>

	/**
	 * Holds the information about the bounding box.
	 * @todo Make base class with different kinds of bounding boxes, AABB, OABB, and Spherical.
	 */
class AABB
{
public:
		/**
		 * Constructor
		 */
	AABB();
		/**
		 * Copy constructor
		 */
	AABB(const AABB & other);
		/**
		 * Destructor
		 */
	~AABB();

		/**
		 * Sets the minimum values in the AABB
		 * @param[in] min The minimum values
		 */
	void SetMin(glm::vec3 min);
		/**
		 * Sets the maximum values in the AABB
		 * @param[in] max The maximum values
		 */
	void SetMax(glm::vec3 max);
		/**
		 * Sets the local coordinates of the object. Used in determining if the bounding boxes collide
		 * @param[in] locals The local coordinates
		 */
	void SetLocalCoordinates(glm::vec3 locals);

		/**
		 * Gets the minium values
		 * @return glm::vec3 The minimum values
		 */
	glm::vec3 GetMin();
		/**
		 * Gets the maximum values
		 * @return glm::vec3 The maximum values
		 */
	glm::vec3 GetMax();
		/**
		 * Gets the local coordinates
		 * @return glm::vec3 The local coordinates
		 */
	glm::vec3 GetLocalCoordinates();

		/**
		 * Determines of the box is collding with another box.
		 * @param[in] other The other AABB
		 * @return bool True if the boxes are considered collding. False if not.
		 */
	bool IsColliding(AABB other);
private:

private:
	glm::vec3 m_min;
	glm::vec3 m_max;
	glm::vec3 m_localCoordinates;
};

#endif
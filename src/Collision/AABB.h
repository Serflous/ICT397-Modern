#ifndef AABB_H
#define AABB_H

#include <glm/vec3.hpp>

class AABB
{
public:
	AABB();
	AABB(const AABB & other);
	~AABB();

	void SetMin(glm::vec3 min);
	void SetMax(glm::vec3 max);
	void SetLocalCoordinates(glm::vec3 locals);

	glm::vec3 GetMin();
	glm::vec3 GetMax();
	glm::vec3 GetLocalCoordinates();

	bool IsColliding(AABB other);
private:

private:
	glm::vec3 m_min;
	glm::vec3 m_max;
	glm::vec3 m_localCoordinates;
};

#endif
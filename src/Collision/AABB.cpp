#include "AABB.h"

AABB::AABB()
{

}

AABB::AABB(const AABB & other)
{
	m_min = other.m_min;
	m_max = other.m_max;
	m_localCoordinates = other.m_localCoordinates;
}

AABB::~AABB()
{

}

void AABB::SetMin(glm::vec3 min)
{
	m_min = min;
}

void AABB::SetMax(glm::vec3 max)
{
	m_max = max;
}

void AABB::SetLocalCoordinates(glm::vec3 locals)
{
	m_localCoordinates = locals;
}

glm::vec3 AABB::GetMin()
{
	return m_min;
}

glm::vec3 AABB::GetMax()
{
	return m_max;
}

glm::vec3 AABB::GetLocalCoordinates()
{
	return m_localCoordinates;
}

bool AABB::IsColliding(AABB other)
{
	glm::vec3 myMin = GetMin() + GetLocalCoordinates();
	glm::vec3 myMax = GetMax() + GetLocalCoordinates();
	glm::vec3 urMin = other.GetMin() + other.GetLocalCoordinates();
	glm::vec3 urMax = other.GetMax() + other.GetLocalCoordinates();

	if (myMax.x < urMin.x || myMin.x > urMax.x)
	{
		return false;
	}
	if (myMax.y < urMin.y || myMin.y > urMax.y)
	{
		return false;
	}
	if (myMax.z < urMin.z || myMin.z > urMax.z)
	{
		return false;
	}
	return true;

}
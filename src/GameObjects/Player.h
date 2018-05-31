#ifndef PLAYER_H
#define PLAYER_H

#include <glm/vec3.hpp>
#include <vector>

#include "../Collision/AABB.h"
#include "RayPicker.h"
#include "../Input/InputManager.h"
#include "Agent.h"

class RayPicker;
class Agent;

class Player
{
public:
	Player();
	Player(const Player & other);
	~Player();

	int GetHealth();
	int GetAmmo();
	glm::vec3 GetPosition();
	bool IsDead();

	void Update(float deltaTime, float pickedId, std::vector<Agent*> agents);

	void TakeDamage(int damage);
	bool FireWeapon();
	void SetPosition(glm::vec3 position);

private:
	int m_health;
	int m_ammo;
	glm::vec3 m_position;
};

#endif
#ifndef PLAYER_H
#define PLAYER_H

#include <gl/glew.h>
#include <glm/vec3.hpp>
#include <vector>

#include "../Collision/AABB.h"
#include "../Input/InputManager.h"
#include "Agent.h"

class RayPicker;
class Agent;

	/**
	 * Contains information about the Player
	 */
class Player
{
public:
		/**
		* Default Constructor
		*/
	Player();
		/**
		* Default copy constructor
		*/
	Player(const Player & other);
		/**
		* Default destructor
		*/
	~Player();

		/**
		* Gets the total amount of health of the player
		* @return int The health
		*/
	int GetHealth();
		/**
		* Gets the total amount of ammo of the player
		* @return int The total amount
		*/
	int GetAmmo();
		/**
		* Gets the position of the player
		* @return glm::vec3 The position
		*/
	glm::vec3 GetPosition();
		/**
		* Returns a boolean value depending on if the player is dead or not.
		* @return bool True if the player is dead, false if not.
		*/
	bool IsDead();

		/**
		* Updates the player.
		* @param[in] deltaTime The time elapsed since the last frame.
		* @param[in] pickedId The ID of the entity the player shot at.
		* @param[in] agents A list of agents.
		*/
	void Update(float deltaTime, float pickedId, std::vector<Agent*> agents);

		/**
		* Cause the player to take damage.
		* @param damage The amount of damage to take.
		*/
	void TakeDamage(int damage);
		/**
		* Cause the player to lose some ammo.
		* @return bool True if there was enough ammo to shoot, false if the player is out of ammo.
		*/
	bool FireWeapon();
		/**
		* Sets the position of the player
		* @param[in] position The new position.
		*/
	void SetPosition(glm::vec3 position);

private:
	int m_health;
	int m_ammo;
	glm::vec3 m_position;
};

#endif
#include "Player.h"

Player::Player()
{
	m_health = 100;
	m_ammo = 100;
}

Player::Player(const Player & other)
{

}

Player::~Player()
{

}

void Player::TakeDamage(int damage)
{
	m_health -= damage;
	std::cout << "Health: " << m_health << std::endl;
	if (m_health < 0)
		m_health = 0;
}

bool Player::FireWeapon()
{
	if (m_ammo <= 0)
	{
		return false;
	}
	m_ammo--;
	return true;
}

int Player::GetHealth()
{
	return m_health;
}

int Player::GetAmmo()
{
	return m_ammo;
}

bool Player::IsDead()
{
	return m_health <= 0;
}

void Player::Update(float deltaTime, float pickedId, std::vector<Agent*> agents)
{
	if (InputManager::GetInstance()->GetButtonState(GLUT_LEFT_BUTTON) == BS_BUTTON_CLICK)
	{
		/*if (pickedId >= 0)
		{
			Agent * agent = agents[pickedId];
			agent->Stop();
		}*/
		std::cout << "Mouse Click ID: " << pickedId << std::endl;
	}
}

void Player::SetPosition(glm::vec3 position)
{
	m_position = position;
}

glm::vec3 Player::GetPosition()
{
	return m_position;
}
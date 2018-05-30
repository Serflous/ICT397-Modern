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

void Player::Update(float deltaTime, std::vector<AABB> boxes, RayPicker picker)
{
	if (InputManager::GetInstance()->GetButtonState(GLUT_LEFT_BUTTON) == BS_BUTTON_CLICK)
	{
		std::cout << "Mouse Click Ray: " << picker.GetRay().x << " " << picker.GetRay().y << " " << picker.GetRay().z << std::endl;
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
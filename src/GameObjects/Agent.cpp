#include "Agent.h"

Agent::Agent()
{
	m_state = State_Idle;
	m_health = 100;
	m_speed = 0.2f;
	m_timeSinceLastAttack = 0;
}

Agent::Agent(const Agent & other)
{

}

Agent::~Agent()
{

}

void Agent::Update(float deltaTime)
{
	float currentTime = m_timeSinceLastStateChange + deltaTime;
	m_timeSinceLastAttack += deltaTime;
	int rng = rand() % 100;
	float distanceBetweenThisAndPlayer = GetDistanceBetweenVectors(m_player->GetPosition(), m_gameObject->GetPosition());
	switch (m_state)
	{
	case State_Idle:
		// If currentTime is lessOrEqual than 1000 and rng is lessOrEqual than 10
		//  -- Change to walking.
		// If currentTime is greater than 1000 and rng is lessOrEuqal than 70
		//  -- Change to walking
		// If player distance is lessOrEqual to 30 and greaterThan 3
		//  -- Change to walking
		// If health is lessThan 10
		//  -- Change to run
		if (currentTime <= 1000 && rng <= 10)
		{
			// Set walk to positon at random
			//ChangeState(State_Walking);
			break;
		}
		if (currentTime > 1000 && rng <= 70)
		{
			// Set walk to position at random
			//ChangeState(State_Walking);
			break;
		}
		if (distanceBetweenThisAndPlayer <= 30 && distanceBetweenThisAndPlayer > 3)
		{
			m_moveToPosition = m_player->GetPosition();
			ChangeState(State_Walking);
			break;
		}
		if (m_health < 10)
		{
			ChangeState(State_Run);
			break;
		}
		break;
	case State_Walking:
		// If distance is lessOrEqual to 30 and greaterThan 3
		//  -- Keep walking
		// If distance is lessOrEqual to 3
		//  -- Change to attack
		// If arrived at location
		//  -- Change to Idle
		// If health is lessThan 10
		//  -- Change to run
		if (distanceBetweenThisAndPlayer <= 30 && distanceBetweenThisAndPlayer > 3)
		{
			m_moveToPosition = m_player->GetPosition();
		}
		if (distanceBetweenThisAndPlayer <= 3)
		{
			ChangeState(State_Attack);
			break;
		}
		// If arrived at location
		if (m_health < 10)
		{
			ChangeState(State_Run);
			break;
		}
		MoveToPosition(deltaTime);
		break;
	case State_Attack:
		// If distance greater than 1
		//  -- Change to walking
		// If health is lessThan 10
		//  -- Change to run
		if (distanceBetweenThisAndPlayer > 3)
		{
			ChangeState(State_Walking);
			break;
		}
		if (m_health < 10)
		{
			ChangeState(State_Run);
			break;
		}
		if (m_timeSinceLastAttack > 1000)
		{
			m_player->TakeDamage(2);
			m_timeSinceLastAttack = 0;
		}
		break;
	case State_Run:
		// If health is greater than 30
		//  --Change to Idle
		if (m_health > 30)
		{
			ChangeState(State_Idle);
			break;
		}
		break;
	}
}

void Agent::ChangeState(State state)
{
	m_state = state;
	m_timeSinceLastStateChange = 0;
}

void Agent::SetPlayer(Player * player)
{
	m_player = player;
}

void Agent::SetGameObject(GameObject * gameObject)
{
	m_gameObject = gameObject;
}

Player * Agent::GetPlayer()
{
	return m_player;
}

GameObject * Agent::GetGameObject()
{
	return m_gameObject;
}

float Agent::GetDistanceBetweenVectors(glm::vec3 vec1, glm::vec3 vec2)
{
	float dx = vec1.x - vec2.x;
	float dy = vec1.y - vec2.y;
	float dz = vec1.z - vec2.z;
	dx *= dx;
	dy *= dy;
	dz *= dz;
	return sqrt(dx + dy + dz);
}

bool Agent::MoveToPosition(float deltaTime)
{
	glm::vec3 currentPosition = m_gameObject->GetPosition();
	glm::vec3 directionVector = m_moveToPosition - currentPosition;
	glm::vec3 currentRotation = m_gameObject->GetRotation();
	directionVector = glm::normalize(directionVector);
	currentPosition += directionVector * m_speed;
	glm::vec3 rotationCross = glm::normalize(glm::cross(currentPosition, m_moveToPosition));
	currentRotation.y += rotationCross.y;
	std::cout << "Rotation: " << currentRotation.y << std::endl;
	m_gameObject->SetPosition(currentPosition);
	m_gameObject->SetRotation(currentRotation);
	return true;
}
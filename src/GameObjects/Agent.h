#ifndef AGENT_H
#define AGENT_H

#include <glm/glm.hpp>
#include <glm/vec3.hpp>

#include "GameObject.h"
#include "Player.h"
#include "../Messaging/Message.h"
#include "../Messaging/Dispatcher.h"

enum State
{
	State_Idle,
	State_Walking,
	State_Attack,
	State_Run
};

class Player;
class Message;

class Agent
{
public:
	Agent();
	Agent(const Agent & other);
	~Agent();

	void SetPlayer(Player * player);
	void SetGameObject(GameObject * gameObject);
	void SetAgentList(std::vector<Agent*> other);

	Player * GetPlayer();
	GameObject * GetGameObject();

	void Update(float deltaTime);
	void Stop();

	void RecieveMessage(Message * message);

private:
	void ChangeState(State state);
	float GetDistanceBetweenVectors(glm::vec3 vec1, glm::vec3 vec2);
	bool MoveToPosition(float deltaTime);
	void SetRandomMovementPosition();
	std::vector<Agent*> CreateListOfLocalAgents();
private:
	GameObject * m_gameObject;
	Player * m_player;
	State m_state;
	float m_timeSinceLastStateChange;
	float m_timeSinceLastAttack;
	float m_health;
	float m_speed;
	bool m_stopped;
	glm::vec3 m_moveToPosition;
	std::vector<Agent*> m_allAgents;
};

#endif
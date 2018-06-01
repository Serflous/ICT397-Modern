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

	/**
	* An autonomouse agent that will perform actions on it's own.
	*/
class Agent
{
public:
		/**
		* Default constructor
		*/
	Agent();
		/**
		* Default copy constructor
		*/
	Agent(const Agent & other);
		/**
		* Default destructor
		*/
	~Agent();

		/**
		* Sets the player that the agent is trying to attack
		* @param[in] player The player.
		*/
	void SetPlayer(Player * player);
		/**
		* Sets the game object that makes up the agent.
		* @param[in] gameObject The game object.
		*/
	void SetGameObject(GameObject * gameObject);
		/**
		* Sets the list of all the agents in the game.
		* @param[in] other A list of agents.
		*/
	void SetAgentList(std::vector<Agent*> other);

		/**
		* Gets the player that is the target of the agent.
		* @return Player* The player
		*/
	Player * GetPlayer();
		/**
		* Gets the game object that makes up the agent.
		* @return GameObject The game object.
		*/
	GameObject * GetGameObject();

		/**
		* Updates the agent.
		* @param[in] deltaTime The amount of time elapsed since the last frame.
		*/
	void Update(float deltaTime);
		/**
		* Stops the agent from moving.
		*/
	void Stop();

		/**
		* Called when a message is dispatched from the message dispatcher.
		* @param[in] message The message recieved.
		*/
	void RecieveMessage(Message * message);

private:
		/**
		* Change the state of the agent.
		* @param[in] state The state of the agent.
		*/
	void ChangeState(State state);
		/**
		* Gets the distance between 2 vectors.
		* @param[in] vec1 The first vector.
		* @param[in] vec2 The second vector.
		* @return float The distance between the two.
		*/
	float GetDistanceBetweenVectors(glm::vec3 vec1, glm::vec3 vec2);
		/**
		* Moves the agent in the direction of the move to vector.
		* @param[in] deltaTime The time elapsed since the last frame.
		* @return bool Unused. Always returns true at this point.
		* @todo Add in location returning
		*/
	bool MoveToPosition(float deltaTime);
		/**
		* Sets a random position for the agent to move to.
		*/
	void SetRandomMovementPosition();
		/**
		* Creates a list of agents that are within a certain radius of the agent.
		* @return std::vector<Agent*> The list of agents.
		*/
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
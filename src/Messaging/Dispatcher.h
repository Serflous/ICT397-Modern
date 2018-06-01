#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <queue>

#include "Message.h"
class Message;
enum MessageValue
{
	Message_TargetLocated,
	Message_ImRunning
};

	/**
	* The dispatcher that dispatches messages to each recipient.
	*/
class Dispatcher
{
private:
		/**
		* Default constructor
		*/
	Dispatcher();
		/**
		* Default copy constructor
		*/
	Dispatcher(const Dispatcher & other);
		/**
		* Default destructor
		*/
	~Dispatcher();
	static Dispatcher * m_instance;
public:
		/**
		* Gets the instance of the singleton object.
		*/
	static Dispatcher * GetInstance();
		/**
		* Dispatchs a message.
		* @param[in] to The reciever of the message.
		* @param[in] from The sender of the message.
		* @param[in] message The message to send.
		*/
	void DispMessage(Agent * to, Agent * from, MessageValue message);
		/**
		* Updates the dispatcher. And tries to send every message in the queue.
		* @param[in] deltaTime The time since the last frame.
		*/
	void Update(float deltaTime);
private:
	std::queue<Message*> m_messages;
};

#endif
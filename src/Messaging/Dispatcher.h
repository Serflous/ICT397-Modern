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
class Dispatcher
{
private:
	Dispatcher();
	Dispatcher(const Dispatcher & other);
	~Dispatcher();
	static Dispatcher * m_instance;
public:
	static Dispatcher * GetInstance();
	void DispMessage(Agent * to, Agent * from, MessageValue message);
	void Update(float deltaTime);
private:
	std::queue<Message*> m_messages;
};

#endif
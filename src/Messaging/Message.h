#ifndef MESSAGE_H
#define MESSAGE_H

#include "../GameObjects/Agent.h"

class Agent;
enum MessageValue;

class Message
{
public:
	Message(MessageValue message, Agent * sender, Agent * reciever);
	Message(const Message & other);
	~Message();

	MessageValue GetMessageValue();
	Agent * GetSender();
	Agent * GetReciever();

private:
	MessageValue m_message;
	Agent * m_sender;
	Agent * m_reciever;
};

#endif
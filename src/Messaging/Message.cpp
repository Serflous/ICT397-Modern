#include "Message.h"

Message::Message(MessageValue message, Agent * sender, Agent * reciever)
{
	m_message = message;
	m_sender = sender;
	m_reciever = reciever;
}

Message::Message(const Message & other)
{
	m_message = other.m_message;
	m_sender = other.m_sender;
	m_reciever = other.m_reciever;
}

Message::~Message()
{

}

MessageValue Message::GetMessageValue()
{
	return m_message;
}

Agent * Message::GetSender()
{
	return m_sender;
}

Agent * Message::GetReciever()
{
	return m_reciever;
}
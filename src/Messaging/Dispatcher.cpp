#include "Dispatcher.h"

Dispatcher * Dispatcher::m_instance = nullptr;

Dispatcher::Dispatcher()
{
	
}

Dispatcher::Dispatcher(const Dispatcher & other)
{

}

Dispatcher::~Dispatcher()
{

}

Dispatcher * Dispatcher::GetInstance()
{
	if (m_instance == nullptr)
		m_instance = new Dispatcher();
	return m_instance;
}

void Dispatcher::Update(float deltaTime)
{
	while (!m_messages.empty())
	{
		Message * message = m_messages.front();
		m_messages.pop();
		Agent * reciever = message->GetReciever();
		reciever->RecieveMessage(message);

	}
}

void Dispatcher::DispMessage(Agent * to, Agent * from, MessageValue value)
{
	Message * message = new Message(value, from, to);
	m_messages.push(message);
}
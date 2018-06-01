#ifndef MESSAGE_H
#define MESSAGE_H

#include "../GameObjects/Agent.h"

class Agent;
enum MessageValue;

	/**
	* Holds information about a message.
	*/
class Message
{
public:
		/**
		* Constructor.
		* @param[in] message The message to send.
		* @param[in] sender The sender of the message.
		* @param[in] reciever The reciever of the message
		*/
	Message(MessageValue message, Agent * sender, Agent * reciever);
		/**
		* Default copy constructor
		*/
	Message(const Message & other);
		/**
		* Default destructor
		*/
	~Message();

		/**
		* Gets the value of the message
		* @return MessageValue The value of the message
		*/
	MessageValue GetMessageValue();
		/**
		* Gets the sender of the message.
		* @return Agent* The sender of the message.
		*/
	Agent * GetSender();
		/**
		* Gets the reciever of the message.
		* @return Agent* The reciever of the message.
		*/
	Agent * GetReciever();

private:
	MessageValue m_message;
	Agent * m_sender;
	Agent * m_reciever;
};

#endif
#ifndef MONSTEROBJECT_H
#define MONSTEROBJECT_H

#include "GameObject.h"

	/**
	 * Monster object, extends from GameObject
	 */
class MonsterObject : public GameObject
{
public:
		/**
		 * Constructor
		 */
	MonsterObject();
		/**
		 * Copy constructor
		 */
	MonsterObject(const MonsterObject & other);
		/**
		 * Destructor
		 */
	~MonsterObject();
private:

private:

};

#endif
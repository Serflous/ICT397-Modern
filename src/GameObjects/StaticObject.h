#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "GameObject.h"

	/**
	 * Static object. Extends from GameObject
	 */
class StaticObject : public GameObject
{
public:
		/**
		 * Constructor
		 */
	StaticObject();
		/**
		 * Copy constructor
		 */
	StaticObject(const StaticObject & other);
		/**
		 * Destructor
		 */
	~StaticObject();
};

#endif
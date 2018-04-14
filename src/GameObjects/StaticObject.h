#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	StaticObject();
	StaticObject(const StaticObject & other);
	~StaticObject();
};

#endif
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

#include "../Resources/ModelOBJ.h"

#include "../Util/MathHelper.h"

class GameObject
{
public:
	GameObject();
	GameObject(const GameObject & other);
	~GameObject();

	void SetModel(ModelOBJ ** model);
	void SetPosition(glm::vec3 position);
	void SetRotation(glm::vec3 rotation);
	void SetScale(glm::vec3 scale);

	glm::vec3 GetPosition();
	glm::vec3 GetRotation();
	glm::vec3 GetScale();

	glm::mat4x4 GetTransformationMatrix();
	ModelOBJ * GetModel();
private:

protected:
	ModelOBJ * m_model;
	glm::vec3 m_position;
	glm::vec3 m_rotation;
	glm::vec3 m_scale;
	//Bounding Box
};

#endif
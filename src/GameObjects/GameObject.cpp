#include "GameObject.h"

GameObject::GameObject()
{

}

GameObject::GameObject(const GameObject & other)
{

}

GameObject::~GameObject()
{

}

void GameObject::SetModel(ModelBase ** model)
{
	m_model = (*model);
}

glm::mat4x4 GameObject::GetTransformationMatrix()
{
	return MathHelper::CreateTransformationMatrix(m_position, m_rotation, m_scale);
}

ModelBase * GameObject::GetModel()
{
	return m_model;
}


void GameObject::SetPosition(glm::vec3 position)
{
	m_position = position;
}

void GameObject::SetRotation(glm::vec3 rotation)
{
	m_rotation = rotation;
}

void GameObject::SetScale(glm::vec3 scale)
{
	m_scale = scale;
}

void GameObject::SetBoundingBox(AABB box)
{
	m_boundingBox = box;
}

glm::vec3 GameObject::GetPosition()
{
	return m_position;
}

glm::vec3 GameObject::GetRotation()
{
	return m_rotation;
}

glm::vec3 GameObject::GetScale()
{
	return m_scale;
}

AABB GameObject::GetBoundingBox()
{
	return m_boundingBox;
}

void GameObject::UpdateBoundingBoxWithPosition()
{
	m_boundingBox.SetLocalCoordinates(m_position);
}

void GameObject::Update(float deltaTime)
{

}

void GameObject::SetHeight(float height)
{
	m_position.y = height;
}

float GameObject::GetModelHeight()
{
	return m_model->GetModelHeight();
}
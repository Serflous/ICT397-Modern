#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

#include "../Resources/Modelling/ModelOBJ.h"
#include "../Collision/AABB.h"

#include "../Util/MathHelper.h"

	/**
	 * The base game object class. Contains information usefull for all objects
	 */
class GameObject
{
public:
		/**
		 * Constructor
		 */
	GameObject();
		/**
		 * Copy constructor
		 */
	GameObject(const GameObject & other);
		/**
		 * Destructor
		 */
	~GameObject();

		/**
		 * Sets the model of the game object.
		 * @param[in] model The model to use
		 */
	void SetModel(ModelBase ** model);
		/**
		 * Sets the position of the game object
		 * @param[in] position The position of the game object
		 */
	void SetPosition(glm::vec3 position);
		/**
		 * Sets the rotation of the game object
		 * @param[in] rotation The rotation of the game object.
		 */
	void SetRotation(glm::vec3 rotation);
		/**
		 * Sets the scale of the game object
		 * @param[in] scale The scale of the game object.
		 */
	void SetScale(glm::vec3 scale);
		/**
		 * Sets the bounding box of the game object
		 * @param box The bouding box used by the object
		 */
	void SetBoundingBox(AABB box);

		/**
		 * Gets the current position of the object
		 * @return glm::vec3 The position of the object.
		 */
	glm::vec3 GetPosition();
		/**
		 * Gets the rotation of the object.
		 * @return glm::vec3 The rotation of the object.
		 */
	glm::vec3 GetRotation();
		/**
		 * Gets the scale of the object.
		 * @return glm::vec3 The scale of the object.
		 */
	glm::vec3 GetScale();
		/**
		 * Gets the bounding box of the object.
		 * @return AABB The bounding box of the object,
		 */
	AABB GetBoundingBox();

		/**
		 * Gets the transformation matrix of the object.
		 * @return glm::mat4x4 Gets the transformation matrix of the object.
		 */
	glm::mat4x4 GetTransformationMatrix();
		/**
		 * Gets the model of the object.
		 * @return ModelOBJ* The model used by the object
		 */
	ModelBase * GetModel();

		/**
		 * Updates the bounding box with the world position of the object.
		 */
	void UpdateBoundingBoxWithPosition();
		/**
		* Sets the height of the object.
		* @param[in] height THe height of the object.
		*/
	void SetHeight(float height);
		/**
		* Updates the game object.
		* @param[in] deltaTime The time elapsed since the last frame.
		*/
	void Update(float deltaTime);
		/**
		* Gets the height of the model by calculating the verts.
		* @return float THe height.
		*/
	float GetModelHeight();
private:

protected:
	ModelBase * m_model;
	glm::vec3 m_position;
	glm::vec3 m_rotation;
	glm::vec3 m_scale;
	AABB m_boundingBox;
};

#endif
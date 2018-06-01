#ifndef MATHHELPER_H
#define MATHHELPER_H

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include "../GameObjects/Camera.h"

class Camera;

	/**
	 * Provides static functions for doing required mathematical calculations.
	 */
class MathHelper
{
public:
		/**
		 * Creates a 3d transformation matrix by compiling all transformations.
		 * @param[in] translation The translation of the object.
		 * @param[in] rotation The rotation of the object.
		 * @param[in] scale The scale of the object
		 */
	static glm::mat4x4 CreateTransformationMatrix(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale);
		/**
		* Creates a 2d transformation matrix by compiling all transformations.
		* @param[in] translation The translation of the object.
		* @param[in] rotation The rotation of the object.
		* @param[in] scale The scale of the object.
		*/
	static glm::mat4x4 CreateTransformationMatrix(glm::vec2 translation, glm::vec2 rotation, glm::vec2 scale);
		/**
		 * Creates a view matrix by compiling the values from a camera.
		 * @param[in] cam The camera to create the view matrix from.
		 */
	static glm::mat4x4 CreateViewMatrix(Camera * cam);
		/**
		 * Tests if a given float is actually an integer.
		 * @param[in] num The number to test.
		 * @return bool True when the number is an integer.
		 */
	static bool IsInteger(float num);
};

#endif
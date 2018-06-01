#ifndef STATICSHADER_H
#define STATICSHADER_H

#include "ShaderBase.h"
#include "../GameObjects/Camera.h"
#include "../Util/MathHelper.h"

class Camera;

	/**
	 * The shader interface class for static objects. Extends the ShaderBase class.
	 */
class StaticShader : public ShaderBase
{
public:
		/**
		 * Constructor
		 */
	StaticShader();
		/**
		 * Copy constructor
		 */
	StaticShader(const StaticShader & other);
		/**
		 * Destructor
		 */
	~StaticShader();

		/**
		 * Binds all the attributes to the shader.
		 */
	void BindAttributes();
		/**
		 * Gets the location of all the uniforms in the shader
		 */
	void GetAllUniforms();
		/**
		 * Loads the projection matrix to the shader.
		 * @param[in] projectionMatrix The projection matrix.
		 */
	void LoadProjectionMatrix(glm::mat4x4 projectionMatrix);
		/**
		 * Loads the transformation matrix to the shader.
		 * @param[in] transformationMatrix The transformation matrix.
		 */
	void LoadTransformationMatrix(glm::mat4x4 transformationMatrix);
		/**
		 * Loads the view matrix to the shader using the camera.
		 * @param[in] cam The camera to set the view to.
		 */
	void LoadViewMatrix(Camera * cam);
		/**
		 * Loads the entity ID to the shader
		 * @param[in] id The ID of the entity.
		 */
	void LoadEntityId(int id);
		/**
		* Loads a boolean value to the shader for if the ID is used.
		* @param[in] useId The boolean value
		*/
	void LoadUseID(bool useId);
private:

protected:

private:
	GLuint m_location_projectionMatrix;
	GLuint m_location_transformationMatrix;
	GLuint m_location_viewMatrix;
	GLuint m_location_entityId;
	GLuint m_location_useId;
};

#endif
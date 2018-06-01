#ifndef ANIMATEDSHADER_H
#define ANIMATEDSHADER_H

#include <glm/mat4x4.hpp>

#include "ShaderBase.h"
#include "../GameObjects/Camera.h"

	/**
	* The shader interface class for loading up values about an animated model
	*/
class AnimatedShader : public ShaderBase
{
public:
		/**
		* Default constructor
		*/
	AnimatedShader();
		/**
		* Default copy constructor
		*/
	AnimatedShader(const AnimatedShader & other);
		/**
		* Default destructor
		*/
	~AnimatedShader();

		/**
		* Binds all the attributes to the shader
		*/
	void BindAttributes();
		/**
		* Gets the location of all the uniforms in the shader
		*/
	void GetAllUniforms();
		/**
		* Loads the projection matrix to the shader
		* @param[in] matrix The projection matrix
		*/
	void LoadProjectionMatrix(glm::mat4x4 matrix);
		/**
		* Loads the transformation matrix to the shader
		* @param[in] matrix The transformation matrix
		*/
	void LoadTransformationMatrix(glm::mat4x4 matrix);
		/**
		* Loads the view matrix from the camera to the shader
		* @param[in] cam The camera.
		*/
	void LoadViewMatrix(Camera * cam);
private:
	GLuint m_location_boneTransforms;
	GLuint m_location_projectionMatrix;
	GLuint m_location_transformationMatrix;
	GLuint m_location_viewMatrix;
};

#endif
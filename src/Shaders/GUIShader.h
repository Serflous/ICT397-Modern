#ifndef GUISHADER_H
#define GUISHADER_H

#include <glm/mat4x4.hpp>

#include "ShaderBase.h"

	/**
	* The interface class for loading values to the GUI shader
	*/
class GUIShader : public ShaderBase
{
public:
		/**
		* Default constructor
		*/
	GUIShader();
		/**
		* Default copy constructor
		*/
	GUIShader(const GUIShader & other);
		/**
		* Default destructor
		*/
	~GUIShader();

		/**
		* Binds all the attributes to the shader
		*/
	void BindAttributes();
		/**
		* Gets the location of all the uniforms in the shader
		*/
	void GetAllUniforms();
		/**
		* Loads the transformation matrix to the shader
		* @param[in] transformationMatrix The transformation matrix.
		*/
	void LoadTransformationMatrix(glm::mat4x4 transformationMatrix);

private:
	int m_location_transformationMatrix;
};

#endif
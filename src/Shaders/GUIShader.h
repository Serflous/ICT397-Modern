#ifndef GUISHADER_H
#define GUISHADER_H

#include <glm/mat4x4.hpp>

#include "ShaderBase.h"

class GUIShader : public ShaderBase
{
public:
	GUIShader();
	GUIShader(const GUIShader & other);
	~GUIShader();

	void BindAttributes();
	void GetAllUniforms();
	void LoadTransformationMatrix(glm::mat4x4 transformationMatrix);

private:
	int m_location_transformationMatrix;
};

#endif
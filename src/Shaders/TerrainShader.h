#ifndef TERRAINSHADER_H
#define TERRAINSHADER_H

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

#include "ShaderBase.h"
#include "../GameObjects/Camera.h"
#include "../Util/MathHelper.h"

	/**
	 * The shader interface class for the terrain. Extends the ShaderBase class.
	 */
class TerrainShader : public ShaderBase
{
public:
		/**
		 * Constructor
		 */
	TerrainShader();
		/**
		 * Copy constructor
		 */
	TerrainShader(const TerrainShader & other);
		/**
		 * Destructor
		 */
	~TerrainShader();

		/**
		 * Binds the attributes used by the shader.
		 */
	void BindAttributes();
		/**
		 * Gets the location of all the uniforms in the shader.
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
		 * Loads the textures to the right samplers in the shader
		 */
	void LoadTextures();
		/**
		 * Loads the light color to the shader. Currently unused.
		 * @param[in] lightColor The color of the shader.
		 */
	void LoadLight(glm::vec3 lightColor);

private:

private:
	GLuint m_location_projectionMatrix;
	GLuint m_location_transformationMatrix;
	GLuint m_location_viewMatrix;
	GLuint m_location_baseTexture;
	GLuint m_location_rTexture;
	GLuint m_location_gTexture;
	GLuint m_location_bTexture;
	GLuint m_location_detailMapTexture;
	GLuint m_location_lightColor;
};

#endif
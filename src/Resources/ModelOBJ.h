#ifndef MODELOBJ_H
#define MODELOBJ_H

#include <vector>
#include <glm/vec3.hpp>

#include "Texture2D.h"

	/**
	 * Contains information about a static 3D model
	 */
class ModelOBJ
{
public:
		/**
		 * Constructor
		 */
	ModelOBJ();
		/**
		 * Constructor.
		 * @param[in] vaoId The ID of the model.
		 * @param[in] vertexCount The number of verticies.
		 */
	ModelOBJ(int vaoId, int vertexCount);
		/**
		 * Copy constructor
		 */
	ModelOBJ(const ModelOBJ & other);
		/**
		 * Destructor
		 */
	~ModelOBJ();

		/**
		 * Sets the VAO ID of the model.
		 * @param[in] vaoId The ID of the VAO
		 */
	void SetVAOID(int vaoId);
		/**
		 * Sets the vertex count of the model.
		 * @param[in] vertexCount The number of verticies
		 */
	void SetVertexCount(int vertexCount);
		/**
		 * Sets the texture of the model.
		 * @param[in] texture The texture used by the model
		 */
	void SetTexture(Texture2D * texture);
		/**
		 * Sets the verticies used by the model. Used for collision detection
		 * @param[in] verts The verticies
		 */
	void SetVertexes(std::vector<glm::vec3> verts);

		/**
		 * Gets the ID of the VAO.
		 * @return int The ID of th VAO
		 */
	int GetVAOID();
		/**
		 * Gets the number of verticies
		 * @return int The number of verts.
		 */
	int GetVertexCount();
		/**
		 * Gets the verticieis used by the model.
		 * @return std::vector<glm::vec3> The vertexes
		 */
	std::vector<glm::vec3> GetVertexes();
		/**
		 * Gets the texture used by the model
		 * @return Texture2D The texture used.
		 */
	Texture2D * GetTexture();

private:

private:
	int m_vaoId;
	int m_vertexCount;
	Texture2D * m_texture;
	std::vector<glm::vec3> m_verts;
};

#endif
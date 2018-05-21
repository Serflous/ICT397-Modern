#ifndef MODELBASE_H
#define MODELBASE_H

#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

#include "../Texture2D.h"

class ModelBase
{
public:
	ModelBase();
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

	void SetUVS(std::vector<glm::vec2> uvs);
	void SetNorms(std::vector<glm::vec3> norms);

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
	std::vector<glm::vec2> GetUVS();
	std::vector<glm::vec3> GetNorms();
	/**
	* Gets the texture used by the model
	* @return Texture2D The texture used.
	*/
	Texture2D * GetTexture();
protected:
	int m_vaoId;
	int m_vertexCount;
	std::vector<glm::vec3> m_verts;
	std::vector<glm::vec2> m_uvs;
	std::vector<glm::vec3> m_norms;

	Texture2D * m_texture;
};

#endif
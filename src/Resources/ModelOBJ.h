#ifndef MODELOBJ_H
#define MODELOBJ_H

#include <vector>
#include <glm/vec3.hpp>

#include "Texture2D.h"

class ModelOBJ
{
public:
	ModelOBJ();
	ModelOBJ(int vaoId, int vertexCount);
	ModelOBJ(const ModelOBJ & other);
	~ModelOBJ();

	void SetVAOID(int vaoId);
	void SetVertexCount(int vertexCount);
	void SetTexture(Texture2D * texture);
	void SetVertexes(std::vector<glm::vec3> verts);

	int GetVAOID();
	int GetVertexCount();
	std::vector<glm::vec3> GetVertexes();
	Texture2D * GetTexture();

private:

private:
	int m_vaoId;
	int m_vertexCount;
	Texture2D * m_texture;
	std::vector<glm::vec3> m_verts;
};

#endif
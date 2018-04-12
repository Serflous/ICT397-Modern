#ifndef MODELOBJ_H
#define MODELOBJ_H

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

	int GetVAOID();
	int GetVertexCount();
	Texture2D * GetTexture();

private:

private:
	int m_vaoId;
	int m_vertexCount;
	Texture2D * m_texture;
};

#endif
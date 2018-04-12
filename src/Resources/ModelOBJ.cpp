#include "ModelOBJ.h"

ModelOBJ::ModelOBJ()
{
	m_vaoId = 0;
	m_vertexCount = 0;
	m_texture = nullptr;
}

ModelOBJ::ModelOBJ(int vaoId, int vertexCount)
{
	m_vaoId = vaoId;
	m_vertexCount = vertexCount;
	m_texture = nullptr;
}

ModelOBJ::ModelOBJ(const ModelOBJ & other)
{
	m_vaoId = other.m_vaoId;
	m_vertexCount = other.m_vertexCount;
}

ModelOBJ::~ModelOBJ()
{

}

void ModelOBJ::SetVAOID(int vaoId)
{
	m_vaoId = vaoId;
}

void ModelOBJ::SetVertexCount(int vertexCount)
{
	m_vertexCount = vertexCount;
}

void ModelOBJ::SetTexture(Texture2D * texture)
{
	m_texture = texture;
}

int ModelOBJ::GetVAOID()
{
	return m_vaoId;
}

int ModelOBJ::GetVertexCount()
{
	return m_vertexCount;
}

Texture2D * ModelOBJ::GetTexture()
{
	return m_texture;
}
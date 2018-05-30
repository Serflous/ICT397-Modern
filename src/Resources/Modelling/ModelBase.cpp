#include "ModelBase.h"

ModelBase::ModelBase()
{
	m_vaoId = 0;
	m_vertexCount = 0;
	m_texture = nullptr;
}

void ModelBase::SetVAOID(int vaoId)
{
	m_vaoId = vaoId;
}

void ModelBase::SetVertexCount(int vertexCount)
{
	m_vertexCount = vertexCount;
}

void ModelBase::SetTexture(Texture2D * texture)
{
	m_texture = texture;
}

void ModelBase::SetVertexes(std::vector<glm::vec3> verts)
{
	m_verts = verts;
}

void ModelBase::SetUVS(std::vector<glm::vec2> uvs)
{
	m_uvs = uvs;
}

void ModelBase::SetNorms(std::vector<glm::vec3> norms)
{
	m_norms = norms;
}

int ModelBase::GetVAOID()
{
	return m_vaoId;
}

int ModelBase::GetVertexCount()
{
	return m_vertexCount;
}

Texture2D * ModelBase::GetTexture()
{
	return m_texture;
}

std::vector<glm::vec3> ModelBase::GetVertexes()
{
	return m_verts;
}

std::vector<glm::vec2> ModelBase::GetUVS()
{
	return m_uvs;
}

std::vector<glm::vec3> ModelBase::GetNorms()
{
	return m_norms;
}

float ModelBase::GetModelHeight()
{
	int maxY = INT_MIN;
	int minY = INT_MAX;
	std::vector<glm::vec3>::iterator vertIter;
	for (vertIter = m_verts.begin(); vertIter != m_verts.end(); vertIter++)
	{
		if ((*vertIter).y > maxY)
			maxY = (*vertIter).y;
		if ((*vertIter).y < minY)
			minY = (*vertIter).y;
	}
	return maxY - minY;
}
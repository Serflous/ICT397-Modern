#include "Terrain.h"

Terrain::Terrain()
{

}

Terrain::Terrain(const Terrain & other)
{

}

Terrain::~Terrain()
{

}

void Terrain::SetScale(glm::vec3 scale)
{
	m_scale = scale;
}

void Terrain::SetSize(int size)
{
	m_size = size;
}

void Terrain::SetTerrainData(unsigned char * data)
{
	m_terrainData = data;
}

void Terrain::SetVAOID(GLuint vaoId)
{
	m_vaoId = vaoId;
}

void Terrain::SetVertexCount(int count)
{
	m_vertexCount = count;
}

glm::vec3 Terrain::GetScale()
{
	return m_scale;
}

int Terrain::GetSize()
{
	return m_size;
}

unsigned char * Terrain::GetTerrainData()
{
	return m_terrainData;
}

GLuint Terrain::GetVAOID()
{
	return m_vaoId;
}

bool Terrain::InBounds(int xPos, int zPos)
{
	return zPos * m_size + xPos <= m_size * m_size;
}

float Terrain::GetHeight(int xPos, int zPos)
{
	if (InBounds(xPos, zPos))
	{
		return (float)m_terrainData[zPos * m_size + xPos];
	}
}

int Terrain::GetVertexCount()
{
	return m_vertexCount;
}
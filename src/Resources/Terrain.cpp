#include "Terrain.h"

Terrain::Terrain()
{
	m_textures = nullptr;
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

void Terrain::SetTextures(TerrainTextures ** texture)
{
	m_textures = (*texture);
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

TerrainTextures * Terrain::GetTextures()
{
	return m_textures;
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

float Terrain::GetRelativeHeight(float xPos, float zPos)
{
	double fract = 0;
	float xPercentage = modf(xPos, &fract);
	float zPercentage = modf(zPos, &fract);

	float sideOneHeightX = GetHeight(floor(xPos), floor(zPos));
	float sideOneHeightZ = GetHeight(ceil(xPos), floor(zPos));
	float sideOneLerped = (1 - xPercentage) * sideOneHeightX + xPercentage * sideOneHeightZ;

	float sideTwoHeightX = GetHeight(floor(xPos), ceil(zPos));
	float sideTwoHeightZ = GetHeight(ceil(xPos), ceil(zPos));
	float sideTwoLerped = (1 - xPercentage) * sideTwoHeightX + xPercentage * sideTwoHeightZ;

	return (1 - zPercentage) * sideOneLerped + zPercentage * sideTwoLerped;

	/*float sideOneAvg = 0, sideTwoAvg = 0;
	sideOneAvg = (GetHeight(floor(xPos), floor(zPos)) + GetHeight(ceil(xPos), floor(zPos))) / 2;
	sideTwoAvg = (GetHeight(floor(xPos), ceil(zPos)) + GetHeight(ceil(xPos), ceil(zPos))) / 2;
	return (sideOneAvg + sideTwoAvg) / 2;*/
}
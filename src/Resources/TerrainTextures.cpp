#include "TerrainTextures.h"

TerrainTextures::TerrainTextures()
{
	m_textureCount = 0;
	m_textures = new Texture2D*[3];
}

TerrainTextures::TerrainTextures(const TerrainTextures & other)
{

}

TerrainTextures::~TerrainTextures()
{

}

void TerrainTextures::SetBaseTexture(Texture2D ** baseTexture)
{
	m_baseTexture = (*baseTexture);
}

void TerrainTextures::AddTexture(Texture2D ** texture)
{
	if (m_textureCount < 3)
	{
		m_textures[m_textureCount++] = (*texture);
	}
}

void TerrainTextures::SetDetailMap(Texture2D ** detailMap)
{
	m_detailMap = (*detailMap);
}

Texture2D * TerrainTextures::GetBaseTexture()
{
	return m_baseTexture;
}

Texture2D * TerrainTextures::GetTexture(int idx)
{
	if (idx < m_textureCount)
	{
		return m_textures[idx];
	}
	return nullptr;
}

Texture2D * TerrainTextures::GetDetailMap()
{
	return m_detailMap;
}
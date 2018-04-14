#ifndef TERRAINTEXTURES_H
#define TERRAINTEXTURES_H

#include "Texture2D.h"

class TerrainTextures
{
public:
	TerrainTextures();
	TerrainTextures(const TerrainTextures & other);
	~TerrainTextures();

	void SetBaseTexture(Texture2D ** baseTexture);
	void AddTexture(Texture2D ** texture);

	Texture2D * GetBaseTexture();
	Texture2D * GetTexture(int idx);
private:

private:
	Texture2D * m_baseTexture;
	Texture2D ** m_textures;

	int m_textureCount;
};

#endif
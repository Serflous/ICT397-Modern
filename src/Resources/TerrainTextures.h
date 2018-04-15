#ifndef TERRAINTEXTURES_H
#define TERRAINTEXTURES_H

#include "Texture2D.h"

	/**
	 * A class for holding the textures for a terrain object
	 */
class TerrainTextures
{
public:
		/**
		 * Constructor
		 */
	TerrainTextures();
		/**
		 * Copy constructor
		 */
	TerrainTextures(const TerrainTextures & other);
		/**
		 * Destructor
		 */
	~TerrainTextures();

		/**
		 * Sets the base texture
		 * @param[in] baseTexture The base texture
		 */
	void SetBaseTexture(Texture2D ** baseTexture);
		/**
		 * Adds a texture to the collection
		 * @param[in] texture The texture to add
		 */
	void AddTexture(Texture2D ** texture);
		/**
		 * Sets the detail map of the terrain
		 * @param[in] detailMap The detail map to add.
		 */
	void SetDetailMap(Texture2D ** detailMap);

		/**
		 * Gets the base texture
		 * @return Texture2D The base texture
		 */
	Texture2D * GetBaseTexture();
		/**
		 * Gets the texture at the specified index
		 * @param[in] idx The index of the texture
		 * @return Texture2D The texture
		 */
	Texture2D * GetTexture(int idx);
		/**
		 * Gets the detail map of the terrain
		 * @return Texture2D The detail map.
		 */
	Texture2D * GetDetailMap();
private:

private:
	Texture2D * m_baseTexture;
	Texture2D * m_detailMap;
	Texture2D ** m_textures;

	int m_textureCount;
};

#endif
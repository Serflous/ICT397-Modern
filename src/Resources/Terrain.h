#ifndef TERRAIN_H
#define TERRAIN_H

#include <glm/vec3.hpp>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "../Resources/TerrainTextures.h"
#include "../Util/MathHelper.h"

	/**
	 * A class that holds information about a terrain
	 */
class Terrain
{
public:
		/**
		 * Constructor
		 */
	Terrain();
		/**
		 * Copy constructor
		 */
	Terrain(const Terrain & other);
		/**
		 * Destructor
		 */
	~Terrain();

		/**
		 * Sets the scale of the terrain
		 * @param[in] scale The scale
		 */
	void SetScale(glm::vec3 scale);
		/**
		 * Sets the size of the terrain
		 * @param[in] size The size
		 */
	void SetSize(int size);
		/**
		 * Sets the terrain data from a heightmap
		 * @param[in] data The data of the heightmap
		 */
	void SetTerrainData(unsigned char * data);
		/**
		 * Sets the VAO ID for the texture
		 * @param[in] vaoId The VAO ID.
		 */
	void SetVAOID(GLuint vaoId);
		/**
		 * Sets the vertex count.
		 * @param[in] count The number of vertecies.
		 * @todo Actually uses index count. Change over.
		 */
	void SetVertexCount(int count);
		/**
		 * Sets the textures used by the terrain
		 * @param[in] texture The textures
		 */
	void SetTextures(TerrainTextures ** texture);

		/**
		 * Gets the scale of the terrain.
		 * @return glm::vec3 The scale of the terrain
		 */
	glm::vec3 GetScale();
		/**
		 * Gets the size of the terrain
		 * @return int The size of the terrain
		 */
	int GetSize();
		/**
		 * Gets the data of the terrain
		 * @return unsigned char * The terrain data.
		 */
	unsigned char * GetTerrainData();
		/**
		 * Gets the VAO ID of the terrain.
		 * @return GLuint The VAO ID.
		 */
	GLuint GetVAOID();

		/**
		 * Gets the height at given coordinates.
		 * @param[in] xPos The x position of the terrain.
		 * @param[in] yPos The y position of the terrain.
		 * @return float The height of the terrain at that point.
		 */
	float GetHeight(int xPos, int zPos);
		/**
		 * Gets the number of verticies in the terrain.
		 * @return int The number of verts
		 * @todo Change over to index count.
		 */
	int GetVertexCount();
		/**
		 * Gets the collection of textures used.
		 * @return TerrainTextures * The textures
		 */
	TerrainTextures * GetTextures();
		/**
		 * Gets the relative height on the terrain, averaging between points on either side.
		 * @param[in] xPos The x position of the terrain
		 * @param[in] yPos The y position of the terrain
		 * @return float The averaged out position.
		 * @todo Make calculations provide a smoother movement.
		 */
	float GetRelativeHeight(float xPos, float zPos);

private:
		/**
		 * Returns if the specified psoition is in the bounds of the terrain array
		 * @param[in] xPos The x position.
		 * @param[in] yPos The y position.
		 * @return bool True if the position is in the array.
		 */
	bool InBounds(int xPos, int zPos);
private:
	glm::vec3 m_scale;
	int m_size;
	int m_vertexCount;
	unsigned char * m_terrainData;
	GLuint m_vaoId;
	TerrainTextures * m_textures;
};

#endif
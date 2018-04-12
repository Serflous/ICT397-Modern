#ifndef TERRAIN_H
#define TERRAIN_H

#include <glm/vec3.hpp>
#include <GL/freeglut.h>

class Terrain
{
public:
	Terrain();
	Terrain(const Terrain & other);
	~Terrain();

	void SetScale(glm::vec3 scale);
	void SetSize(int size);
	void SetTerrainData(unsigned char * data);
	void SetVAOID(GLuint vaoId);
	void SetVertexCount(int count);

	glm::vec3 GetScale();
	int GetSize();
	unsigned char * GetTerrainData();
	GLuint GetVAOID();

	float GetHeight(int xPos, int zPos);
	int GetVertexCount();

private:
	bool InBounds(int xPos, int zPos);
private:
	glm::vec3 m_scale;
	int m_size;
	int m_vertexCount;
	unsigned char * m_terrainData;
	GLuint m_vaoId;
};

#endif
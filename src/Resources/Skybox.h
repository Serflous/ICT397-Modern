#ifndef SKYBOX_H
#define SKYBOX_H

#include <vector>

class Skybox
{
public:
	Skybox();
	Skybox(const Skybox & other);
	~Skybox();

	void SetDimensions(int width, int height);
	void SetIDs(int vaoId, int texId);
	void SetVertexCount(int vertexCount);

	int GetVAOID();
	int GetTextureID();
	int GetVertexCount();

private:
	int m_textureWidth;
	int m_textureHeight;
	int m_vaoId;
	int m_texId;
	int m_vertexCount;
};

#endif
#include "Skybox.h"

Skybox::Skybox()
{

}

Skybox::Skybox(const Skybox & other)
{

}

Skybox::~Skybox()
{

}

void Skybox::SetDimensions(int width, int height)
{
	m_textureWidth = width;
	m_textureHeight = height;
}

void Skybox::SetIDs(int vaoId, int texId)
{
	m_vaoId = vaoId;
	m_texId = texId;
}

int Skybox::GetTextureID()
{
	return m_texId;
}

int Skybox::GetVAOID()
{
	return m_vaoId;
}


void Skybox::SetVertexCount(int vertexCount)
{
	m_vertexCount = vertexCount;
}

int Skybox::GetVertexCount()
{
	return m_vertexCount;
}
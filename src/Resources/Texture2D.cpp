#include "Texture2D.h"

Texture2D::Texture2D()
{
	m_textureId = 0;
}

Texture2D::Texture2D(int textureId)
{
	m_textureId = textureId;
}

Texture2D::Texture2D(const Texture2D & other)
{
	m_textureId = other.m_textureId;
}

Texture2D::~Texture2D()
{

}

void Texture2D::BindTexture()
{
	glBindTexture(GL_TEXTURE_2D, m_textureId);
}

void Texture2D::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::SetTextureId(int texId)
{
	m_textureId = texId;
}

int Texture2D::GetTextureId()
{
	return m_textureId;
}

void Texture2D::Destroy()
{
	glDeleteTextures(1, &m_textureId);
}
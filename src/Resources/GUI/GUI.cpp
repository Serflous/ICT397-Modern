#include "GUI.h"

GUI::GUI()
{

}

GUI::GUI(const GUI & other)
{

}

GUI::~GUI()
{

}

void GUI::AddTexture(TextureGUI * texture)
{
	m_textures.push_back(texture);
}

std::vector<TextureGUI*> GUI::GetTextures()
{
	return m_textures;
}

int GUI::GetVAOID()
{
	return m_vaoId;
}

int GUI::GetVertexCount()
{
	return m_vertexCount;
}

void GUI::SetVAOID(int vaoId)
{
	m_vaoId = vaoId;
}

void GUI::SetVertexCount(int vertexCount)
{
	m_vertexCount = vertexCount;
}
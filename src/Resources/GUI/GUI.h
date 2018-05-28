#ifndef GUI_H
#define GUI_H

#include <vector>

#include "TextureGUI.h"

class GUI
{
public:
	GUI();
	GUI(const GUI & other);
	~GUI();

	void AddTexture(TextureGUI * texture);
	std::vector<TextureGUI*> GetTextures();
	int GetVAOID();
	int GetVertexCount();

	void SetVAOID(int vaoId);
	void SetVertexCount(int vertexCount);

private:
	std::vector<TextureGUI*> m_textures;
	int m_vaoId;
	int m_vertexCount;
};

#endif
#ifndef TEXTUREGUI_H
#define TEXTUREGUI_H

#include <glm/vec2.hpp>

#include "../Texture2D.h"

class TextureGUI
{
public:
	TextureGUI(Texture2D * texture, glm::vec2 position, glm::vec2 rotation, glm::vec2 scale);
	TextureGUI(const TextureGUI & other);
	~TextureGUI();

	Texture2D * GetTexture();
	glm::vec2 GetPosition();
	glm::vec2 GetRotation();
	glm::vec2 GetScale();

private:
	Texture2D * m_texture;
	glm::vec2 m_position;
	glm::vec2 m_scale;
	glm::vec2 m_rotation;
};

#endif
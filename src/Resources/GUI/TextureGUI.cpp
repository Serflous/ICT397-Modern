#include "TextureGUI.h"

TextureGUI::TextureGUI(Texture2D * texture, glm::vec2 position, glm::vec2 rotation, glm::vec2 scale)
{
	m_texture = texture;
	m_position = position;
	m_rotation = rotation;
	m_scale = scale;
}

TextureGUI::TextureGUI(const TextureGUI & other)
{
	
}

TextureGUI::~TextureGUI()
{

}

Texture2D * TextureGUI::GetTexture()
{
	return m_texture;
}

glm::vec2 TextureGUI::GetPosition()
{
	return m_position;
}

glm::vec2 TextureGUI::GetRotation()
{
	return m_rotation;
}

glm::vec2 TextureGUI::GetScale()
{
	return m_scale;
}
#ifndef TEXTUREGUI_H
#define TEXTUREGUI_H

#include <glm/vec2.hpp>

#include "../Texture2D.h"

	/**
	* Information about a texture for a GUI item.
	*/
class TextureGUI
{
public:
		/**
		* Constructor.
		* @param[in] texture The texture to draw on the GUI.
		* @param[in] position The position of the GUI item.
		* @param[in] rotation The rotation of the GUI item.
		* @param[in] scale The scale of the GUI iterm
		*/
	TextureGUI(Texture2D * texture, glm::vec2 position, glm::vec2 rotation, glm::vec2 scale);
		/**
		* Default copy constructor
		*/
	TextureGUI(const TextureGUI & other);
		/**
		* Default destructor
		*/
	~TextureGUI();

		/**
		* Gets the texture of the GUI
		* @return Texture2D* The texture
		*/
	Texture2D * GetTexture();
		/**
		* Gets the position of th GUI
		* @return glm::vec2 The position
		*/
	glm::vec2 GetPosition();
		/**
		* Gets the rotation of the GUI
		* @return glm::vec2 The rotation
		*/
	glm::vec2 GetRotation();
		/**
		* Gets the scale of the GUI
		* @return glm::vec2 The scale
		*/
	glm::vec2 GetScale();

private:
	Texture2D * m_texture;
	glm::vec2 m_position;
	glm::vec2 m_scale;
	glm::vec2 m_rotation;
};

#endif
#ifndef GUI_H
#define GUI_H

#include <vector>

#include "TextureGUI.h"
	/**
	* The GUI that will be displayed over the 3d scene
	*/
class GUI
{
public:
		/**
		* Default constructor
		*/
	GUI();
		/**
		* Default copy constructor
		*/
	GUI(const GUI & other);
		/**
		* Default destructor
		*/
	~GUI();

		/**
		* Adds a texture to the list
		* @param[in] texture The texture to add
		*/
	void AddTexture(TextureGUI * texture);
		/**
		* Gets a list of all the textures to draw.
		* @return std::vector<TextureGUI*> The list of textures.
		*/
	std::vector<TextureGUI*> GetTextures();
		/**
		* Gets the VAO Id
		* @return int The ID of the VAO
		*/
	int GetVAOID();
		/**
		* Gets the number of verts.
		* @return int The number of verts
		*/
	int GetVertexCount();

		/**
		* Sets the ID of the VAO
		* @param[in] vaoId The ID of the VAO
		*/
	void SetVAOID(int vaoId);
		/**
		* Sets the numbner of verts.
		* @param[in] vertexCount The number of verts.
		*/
	void SetVertexCount(int vertexCount);

private:
	std::vector<TextureGUI*> m_textures;
	int m_vaoId;
	int m_vertexCount;
};

#endif
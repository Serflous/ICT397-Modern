#ifndef SKYBOX_H
#define SKYBOX_H

#include <vector>
	/**
	* Holds the information about a skybox
	*/
class Skybox
{
public:
		/**
		* Default constructor
		*/
	Skybox();
		/**
		* Default copy constructor
		*/
	Skybox(const Skybox & other);
	/**
	* Default destructor
	*/
	~Skybox();

		/**
		* Sets the dimensions of the skybox texture.
		* @param[in] width The width of the texture
		* @param[in] height The height of the texture
		*/
	void SetDimensions(int width, int height);
		/**
		* Sets the IDs of the skybox
		* @param[in] vaoId The ID of the VAO
		* @param[in] texId The ID of the texture
		*/
	void SetIDs(int vaoId, int texId);
		/**
		* Sets the vertex count.
		* @param[in] vertexCount The number of verts.
		*/
	void SetVertexCount(int vertexCount);

		/**
		* Gets the ID of the VAO
		* @return int The ID of the VAO
		*/
	int GetVAOID();
		/**
		* Gets the ID of the texture.
		* @return int The ID of the texture
		*/
	int GetTextureID();
		/**
		* Gets the number of verts.
		* @return int The number of verts.
		*/
	int GetVertexCount();

private:
	int m_textureWidth;
	int m_textureHeight;
	int m_vaoId;
	int m_texId;
	int m_vertexCount;
};

#endif
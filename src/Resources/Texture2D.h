#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

	/**
	 * A class for holding the id of a 2D texture, and binding it to OpenGL when required.
	 */
class Texture2D
{
public:
		/**
		 * Constructor
		 */
	Texture2D();
		/**
		 * Constructor
		 * @param[in] textureId The id of the texture
		 */
	Texture2D(int textureId);
		/**
		 * Copy constructor
		 */
	Texture2D(const Texture2D & other);
		/**
		 * Destructor
		 */
	~Texture2D();

		/**
		 * Binds the texture to OpenGL
		 */
	void BindTexture();
		/**
		 * Unbinds the texture
		 */
	void Unbind();
		/**
		 * Destroys the texture
		 */
	void Destroy();

		/**
		 * Sets the texture ID
		 * @param[in] texId The ID of the texture
		 */
	void SetTextureId(int texId);
		/**
		 * Returns the texture ID
		 * @return int The ID of the texture
		 */
	int GetTextureId();
private:

private:
	GLuint m_textureId;
};

#endif
#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include <GL/freeglut.h>
#include <iostream>

class Texture2D
{
public:
	Texture2D();
	Texture2D(int textureId);
	Texture2D(const Texture2D & other);
	~Texture2D();

	void BindTexture();
	void Unbind();
	void Destroy();

	void SetTextureId(int texId);
	int GetTextureId();
private:

private:
	GLuint m_textureId;
};

#endif
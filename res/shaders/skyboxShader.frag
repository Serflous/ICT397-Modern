#version 400

in vec3 textureCoords;
out vec4 out_Color;

uniform samplerCube cube;

void main(void)
{
	out_Color = texture(cube, textureCoords);
}
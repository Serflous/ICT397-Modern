#version 400

in vec3 textureCoords;
out vec4 out_Color;

uniform samplerCube cube;

layout(location=0) out vec4	RenderColor;
layout(location=1) out vec4 PickingColor;

void main(void)
{
	RenderColor = texture(cube, textureCoords);
	PickingColor = vec4(0.0f, 0.0f, 0.0f, 0.0f);
}
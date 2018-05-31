#version 400 core

in vec2 pass_textureCoords;
in int pass_entityId;

out vec4 out_Color;

uniform sampler2D textureSampler;
uniform float useId;
uniform uint entityId;

layout(location=0) out vec4	RenderColor;
layout(location=1) out vec4 PickingColor;

void main(void)
{
	//out_Color = texture(textureSampler, pass_textureCoords);
	RenderColor = texture(textureSampler, pass_textureCoords);
	PickingColor = vec4(floor(entityId)/255.0f, 0.0, 0.0, useId);
}
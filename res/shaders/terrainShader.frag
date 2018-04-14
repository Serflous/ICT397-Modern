#version 400 core

in vec2 pass_textureCoords;
in float pass_height;

out vec4 out_Color;

uniform sampler2D baseTexture;
uniform sampler2D rTexture;
uniform sampler2D gTexture;
uniform sampler2D bTexture;

void main(void)
{
	if(pass_height < 64)
	{
		out_Color = texture(baseTexture, pass_textureCoords);
	}
	else if(pass_height >= 64 && pass_height < 128)
	{
		out_Color = texture(rTexture, pass_textureCoords);
	}
	else if(pass_height >= 128 && pass_height < 192)
	{
		out_Color = texture(gTexture, pass_textureCoords);
	}
	else if(pass_height >= 192 && pass_height <= 255)
	{
		out_Color = texture(bTexture, pass_textureCoords);
	}
	else
	{
		out_Color = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	}
}
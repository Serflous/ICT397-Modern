#version 400 core

in vec2 pass_textureCoords;
in float pass_height;
in vec2 pass_detailTexCoords;

out vec4 out_Color;

uniform sampler2D baseTexture;
uniform sampler2D rTexture;
uniform sampler2D gTexture;
uniform sampler2D bTexture;
uniform sampler2D detailMapTexture;

uniform vec3 lightColor;

vec3 lowLight = vec3(0.4f, 0.4f, 0.4f);
vec3 highLight = vec3(1.0f, 1.0f, 1.0f);

layout(location=0) out vec4	RenderColor;
layout(location=1) out vec4 PickingColor;


void main(void)
{
	float relativeHeight = pass_height / 255.0f;

	if(relativeHeight < 0.5f)
	{
		RenderColor = texture(baseTexture, pass_textureCoords);
	}
	else if(relativeHeight >= 0.5f && relativeHeight < 0.6f)
	{
		RenderColor = texture(rTexture, pass_textureCoords);
	}
	else if(relativeHeight >= 0.6f && relativeHeight < 0.8f)
	{
		RenderColor = texture(gTexture, pass_textureCoords);
	}
	else if(relativeHeight >= 0.8f && relativeHeight <= 1.0f)
	{
		RenderColor = texture(bTexture, pass_textureCoords);
	}
	else
	{
		RenderColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	}
	PickingColor = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	vec4 detailColor = texture(detailMapTexture, pass_detailTexCoords);

	vec3 lightLevel = highLight - lowLight;
	lightLevel = lightLevel * relativeHeight;
	lightLevel = lightLevel + lowLight;

	RenderColor = mix(RenderColor, detailColor, 0.25f);
	RenderColor = RenderColor * vec4(lightLevel, 1.0f);
	
	
}
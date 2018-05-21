#version 400 core

const int MAX_BONES = 30;
const int MAX_WEIGHTS = 3;

in vec3 position;
in vec2 textureCoords;
in vec3 normal;
in ivec3 boneIndicies;
in vec3 weights;

out vec2 pass_textureCoords;

uniform mat4 boneTransforms[MAX_BONES];
uniform mat4 transformationMatrix;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

void main(void)
{
	vec4 cumulLocalPosition = vec4(0.0);

	for(int i = 0; i < MAX_WEIGHTS; i++)
	{
		mat4 boneTransform = boneTransforms[boneIndicies[i]];
		vec4 posePosition = boneTransform * vec4(position, 1.0);
		cumulLocalPosition += posePosition * weights[i];
	}
	
	gl_Position = projectionMatrix * viewMatrix * cumulLocalPosition;
	pass_textureCoords = textureCoords;
}
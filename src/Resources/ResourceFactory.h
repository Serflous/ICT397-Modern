#ifndef RESOURCEFACTORY_H
#define RESOURCEFACTORY_H

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <GL/glew.h>

#include "Texture2D.h"
#include "ModelOBJ.h"
#include "Terrain.h"
#include "../Shaders/ShaderBase.h"

class ResourceFactory
{
public:
	static ResourceFactory * GetInstance();

	void LoadTexture(const char * filename, int x, int y, Texture2D ** texture);
	void LoadOBJ(const char * filename, ModelOBJ ** model, Texture2D * texture);
	void LoadShader(const char * vertFilename, const char * fragFilename, ShaderBase ** shader);
	void LoadTerrain(const char * heightmap, int size, Terrain ** terrain);

private:
	ResourceFactory();
	ResourceFactory(const ResourceFactory & other);
	~ResourceFactory();

	void ProcessVertex(std::string v, std::string t, std::string n, std::vector<int> &indicies, std::vector<glm::vec2> &textures, std::vector<glm::vec3> &normals, std::vector<float> &textureArray, std::vector<float> &normalArray);
	int LoadToVAO(std::vector<float> positions, std::vector<float> textureCoords, std::vector<float> normals, std::vector<int> indicies);
	int CreateVAO();
	void AddDataToVAO(int attribList, int coordSize, std::vector<float> data);
	void AddIndiciesToVAO(std::vector<int> indicies);
	void BindVAO(int vaoId);
	void UnbindVAO();
	int LoadShaderFile(const char * filename, int type);

private:
	static ResourceFactory * m_instance;
	std::vector<Texture2D*> m_textures;
	std::vector<ModelOBJ*> m_models;
	std::vector<int> m_vaoIds;
	std::vector<int> m_vboIds;
};

#endif
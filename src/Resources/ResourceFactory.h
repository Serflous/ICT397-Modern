#ifndef RESOURCEFACTORY_H
#define RESOURCEFACTORY_H

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <limits>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <GL/glew.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/vector3.h>

#include "TerrainTextures.h"
#include "Texture2D.h"
#include "Modelling/ModelOBJ.h"
#include "Modelling/ModelAnimated.h"
#include "Terrain.h"
#include "../Shaders/ShaderBase.h"
#include "../GameObjects/GameObject.h"
#include "../Resources/GUI/GUI.h"
#include "Skybox.h"

class Terrain;
class GameObject;

	/**
	 * Singleton class for creating game objects.
	 */
class ResourceFactory
{
public:
		/**
		 * Returns the singleton instance of the class. If it is not yet created it will be created.
		 * @return ResourceFactory * The instance to the class.
		 */
	static ResourceFactory * GetInstance();

		/**
		 * Loads a texture into OpenGL
		 * @param[in] filename The filename of the texture.
		 * @param[in] x The width of the image.
		 * @param[in] y The height of the image.
		 * @param[out] texture The Texture2D to create the image into.
		 */
	void LoadTexture(const char * filename, int x, int y, Texture2D ** texture);
		/**
		 * Loads an OBJ file into OpenGL
		 * @param[in] filename The filename of the object.
		 * @param[out] model The ModelOBJ to create the object into.
		 * @param[in] texture The texture that the model uses.
		 */
	void LoadOBJ(const char * filename, ModelOBJ ** model, Texture2D * texture);
		/**
		 * Loads and compiles the shader.
		 * @param[in] vertFilename The filename of the vertex shader.
		 * @param[in] fragFilename The filename of the fragment shader.
		 * @param[out] shader The ShaderBase object to load the shader into.
		 */
	void LoadShader(const char * vertFilename, const char * fragFilename, ShaderBase ** shader);
		/**
		 * Loads in a collada file.
		 * @param[in] filename The location of the collada file.
		 * @param[out] model The ModelAnimated object.
		 * @param[in] texture The texture that the model uses.
		 */
	void LoadCollada(const char * filename, ModelAnimated ** model, Texture2D * texture);
		/**
		 * Loads a given terrain file.
		 * @param[in] heightmap The location of the heightmap.
		 * @param[in] mapSize The size of the heightmap.
		 * @param[out] terrain The terrain object to load the terrain into.
		 * @param[in] terrainTextures The textures used with the terrain.
		 * @param[in] scale The scale of the terrain
		 */
	void LoadTerrain(const char * heightmap, int mapSize, Terrain ** terrain, TerrainTextures ** terrainTextures, glm::vec3 scale);
		/**
		 * Loads the game object.
		 * @param[in] model The model that the object uses.
		 * @param[in] position The position of the game object.
		 * @param[in] rotation The rotation of the game object.
		 * @param[in] scale The scale of the game object.
		 * @param[out] object The GmaeObject to load the object into.
		 */
	void LoadGameObject(ModelBase * model, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, GameObject ** object);
		/**
		* Loads a skybox into the game.
		* @param[out] skybox The skybox object.
		* @param[in] textures A list of texture locations.
		* @param[in] size The size of the textures.
		*/
	void LoadSkybox(Skybox ** skybox, std::vector<const char *> textures, int size);
		/**
		* Loads the GUI Quad into the game.
		* @param[out] The GUI object to load it into.
		*/
	void LoadGUIQuad(GUI ** gui);

private:
		/**
		 * Constructor
		 */
	ResourceFactory();
		/**
		 * Copy constructor
		 */
	ResourceFactory(const ResourceFactory & other);
		/**
		 * Destructor
		 */
	~ResourceFactory();

		/**
		 * Processes a vertex from the OBJ file.
		 * @param[in] v The index of the vertex.
		 * @param[in] t The index of the texture.
		 * @param[in] n The index of the normal.
		 * @param[out] indicies The array of indicies.
		 * @param[in] textures An array of texture coordinates.
		 * @param[in] normals An array of normals.
		 * @param[out] textureArray The return array of ordered textures.
		 * @param[out] normalArray The return array of ordered normals.
		 */
	void ProcessVertex(std::string v, std::string t, std::string n, std::vector<int> &indicies, std::vector<glm::vec2> &textures, std::vector<glm::vec3> &normals, std::vector<float> &textureArray, std::vector<float> &normalArray);
		/**
		 * Loads data to a VAO.
		 * @param[in] positions The positions to load to a VAO.
		 * @param[in] textureCoords The UV map to load to a VAO.
		 * @param[in] normals The normals to load to a VAO.
		 * @param[in] indicies The indicies to load to a VAO.
		 */
	int LoadToVAO(std::vector<float> positions, std::vector<float> textureCoords, std::vector<float> normals, std::vector<int> indicies);
		/**
		 * Creates a VAO and returns the ID.
		 * @return int The ID of the VAO
		 */
	int CreateVAO();
		/**
		 * Adds some data to a VBO in the VAO.
		 * @param[in] attribList The list to store the data in.
		 * @param[in] coordSize The size of the data being added.
		 * @param[in] data The data to add
		 */
	void AddDataToVAO(int attribList, int coordSize, std::vector<float> data);
		/**
		 * Adds the index list to a VBO in the VAO.
		 * @param[in] indicies The index list
		 */
	void AddIndiciesToVAO(std::vector<int> indicies);
		/**
		 * Binds a VAO after creation
		 * @param[in] vaoId The ID of the VAO.
		 */
	void BindVAO(int vaoId);
		/**
		 * Unbinds the VAO after it has finished being written too.
		 */
	void UnbindVAO();
		/**
		 * Loads and compiles a shader file.
		 * @param[in] filename The filename of the shader.
		 * @param[in] type The type of the shader. Vertex or Fragment.
		 */
	int LoadShaderFile(const char * filename, int type);
		/**
		* Loads the skybox texture data.
		* @param[in] filename The location of the textures.
		* @param[in] size The size of the texture.
		*/
	unsigned char * LoadSkyboxTextureData(const char * filename, int size);

private:
	static ResourceFactory * m_instance;
	std::vector<Texture2D*> m_textures;
	std::vector<ModelBase*> m_models;
	std::vector<int> m_vaoIds;
	std::vector<int> m_vboIds;
};

#endif
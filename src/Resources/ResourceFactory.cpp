#include "ResourceFactory.h"

ResourceFactory * ResourceFactory::m_instance;

ResourceFactory::ResourceFactory()
{

}

ResourceFactory::ResourceFactory(const ResourceFactory & other)
{

}

ResourceFactory::~ResourceFactory()
{

}

ResourceFactory * ResourceFactory::GetInstance()
{
	if (!m_instance)
	{
		m_instance = new ResourceFactory();
	}
	return m_instance;
}

void ResourceFactory::LoadTexture(const char * filename, int x, int y, Texture2D ** texture)
{
	unsigned char * data;
	FILE * fp;

	fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		std::cerr << "Texture not found: " << filename << std::endl;
		return;
	}

	data = (unsigned char *)malloc(x * y * 4);

	fread(data, x * y * 4, 1, fp);
	fclose(fp);

	GLuint texId = 0;

	glGenTextures(1, &texId);

	glBindTexture(GL_TEXTURE_2D, texId);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)data);
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, x, y, GL_RGBA, GL_UNSIGNED_BYTE, data);

	free(data);

	*texture = new Texture2D(texId);

	m_textures.push_back(*texture);

	std::cout << "Texture loaded: " << filename << " with ID-" << texId << std::endl;

}

void ResourceFactory::LoadOBJ(const char * filename, ModelOBJ ** model, Texture2D * texture)
{
	using namespace std;
	ifstream in(filename);
	if (!in)
	{
		cerr << "File not found: " << filename << endl;
		return;
	}

	vector<glm::vec3> verticies;
	vector<glm::vec2> textures;
	vector<glm::vec3> normals;
	vector<int> indicies;
	vector<float> verticesArray;
	vector<float> normalArray;
	vector<float> textureArray;
	string line;

	while (getline(in, line))
	{
		if (line.substr(0, 2) == "v ")
		{
			istringstream s(line.substr(2));
			glm::vec3 v;
			s >> v.x; s >> v.y; s >> v.z;
			verticies.push_back(v);
		}
		else if (line.substr(0, 3) == "vn ")
		{
			istringstream s(line.substr(3));
			glm::vec3 n;
			s >> n.x; s >> n.y; s >> n.z;
			normals.push_back(n);
		}
		else if (line.substr(0, 3) == "vt ")
		{
			istringstream s(line.substr(3));
			glm::vec2 uv;
			s >> uv.x; s >> uv.y;
			uv.y = 1 - uv.y;
			textures.push_back(uv);
		}
		else if (line.substr(0, 2) == "f ")
		{
			istringstream s(line.substr(2));
			string a, b, c;
			string f1v, f1t, f1n, f2v, f2t, f2n, f3v, f3t, f3n;
			s >> a; s >> b; s >> c;

			stringstream ss(a);
			getline(ss, f1v, '/');
			getline(ss, f1t, '/');
			getline(ss, f1n);

			ss.clear();
			ss.str(b);
			getline(ss, f2v, '/');
			getline(ss, f2t, '/');
			getline(ss, f2n);

			ss.clear();
			ss.str(c);
			getline(ss, f3v, '/');
			getline(ss, f3t, '/');
			getline(ss, f3n);

			ProcessVertex(f1v, f1t, f1n, indicies, textures, normals, textureArray, normalArray);
			ProcessVertex(f2v, f2t, f2n, indicies, textures, normals, textureArray, normalArray);
			ProcessVertex(f3v, f3t, f3n, indicies, textures, normals, textureArray, normalArray);
		}
	}
	vector<glm::vec3>::iterator vertIter;
	for (vertIter = verticies.begin(); vertIter != verticies.end(); vertIter++)
	{
		verticesArray.push_back((*vertIter).x);
		verticesArray.push_back((*vertIter).y);
		verticesArray.push_back((*vertIter).z);
	}

	int vaoId = LoadToVAO(verticesArray, textureArray, normalArray, indicies);
	*model = new ModelOBJ(vaoId, indicies.size());
	(*model)->SetTexture(texture);

	cout << "OBJ Model loaded: " << filename << " with ID-" << vaoId << " and " << (*model)->GetVertexCount() << " verts" << endl;
}

void ResourceFactory::LoadShader(const char * vertShader, const char * fragShader, ShaderBase ** shader)
{
	GLuint vertexShaderId = LoadShaderFile(vertShader, GL_VERTEX_SHADER);
	if (vertexShaderId <= 0)
	{
		return;
	}
	std::cout << "Vertex shader loaded: " << vertShader << " with ID-" << vertexShaderId << std::endl;
	GLuint fragmentShaderId = LoadShaderFile(fragShader, GL_FRAGMENT_SHADER);
	if (fragmentShaderId <= 0)
	{
		return;
	}
	std::cout << "Fragment shader loaded: " << fragShader << " with ID-" << fragmentShaderId << std::endl;
	GLuint programId = glCreateProgram();
	glAttachShader(programId, vertexShaderId);
	glAttachShader(programId, fragmentShaderId);
	(*shader)->SetProgramID(programId);
	(*shader)->SetVertexShaderID(vertexShaderId);
	(*shader)->SetFragmentShaderID(fragmentShaderId);
	(*shader)->BindAttributes();
	glLinkProgram(programId);
	glValidateProgram(programId);
	(*shader)->GetAllUniforms();
	std::cout << "Shader program successfully loaded with ID-" << programId << std::endl;
}

int ResourceFactory::LoadShaderFile(const char * filename, int type)
{
	using namespace std;
	string shaderContent, line = "";
	ifstream fileStream(filename);
	int programId;
	if (!fileStream.is_open())
	{
		cerr << filename << " shader failed to open." << endl;
		return 0;
	}
	while (getline(fileStream, line))
	{
		shaderContent.append(line + '\n');
	}
	fileStream.close();

	programId = glCreateShader(type);
	const char * shaderSource = shaderContent.c_str();
	cout << filename << " loaded successfully. Compiling..." << endl;
	glShaderSource(programId, 1, &shaderSource, NULL);
	glCompileShader(programId);
	GLint compileStatus = GL_FALSE;
	glGetShaderiv(programId, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus == GL_FALSE)
	{
		cerr << filename << " failed to compile." << endl;
		GLint maxLength = 0;
		glGetShaderiv(programId, GL_INFO_LOG_LENGTH, &maxLength);
		GLchar * errorLog = new GLchar[maxLength];
		glGetShaderInfoLog(programId, maxLength, &maxLength, errorLog);
		cerr << errorLog << endl;
		return 0;
	}
	else
	{
		cout << filename << " compiled successfully." << endl;
	}

	return programId;

}

void ResourceFactory::ProcessVertex(std::string v, std::string t, std::string n, std::vector<int> &indicies, std::vector<glm::vec2> &textures, std::vector<glm::vec3> &normals, std::vector<float> &textureArray, std::vector<float> &normalArray)
{
	int currentVertexPointer = atoi(v.c_str()) - 1;
	int texPointer = atoi(t.c_str()) - 1;
	int normPointer = atoi(n.c_str()) - 1;

	indicies.push_back(currentVertexPointer);

	glm::vec2 currentTex = textures[texPointer];
	textureArray.push_back(currentTex.x);
	textureArray.push_back(currentTex.y);

	glm::vec3 currentNorm = normals[normPointer];
	normalArray.push_back(currentNorm.x);
	normalArray.push_back(currentNorm.y);
	normalArray.push_back(currentNorm.z);

}

int ResourceFactory::LoadToVAO(std::vector<float> positions, std::vector<float> textureCoords, std::vector<float> normals, std::vector<int> indicies)
{
	int vaoId = CreateVAO();
	BindVAO(vaoId);
	AddIndiciesToVAO(indicies);
	AddDataToVAO(0, 3, positions);
	AddDataToVAO(1, 2, textureCoords);
	AddDataToVAO(2, 3, normals);
	UnbindVAO();
	return vaoId;
}

int ResourceFactory::CreateVAO()
{
	GLuint vaoId = 0;
	glGenVertexArrays(1, &vaoId);
	m_vaoIds.push_back(vaoId);
	return vaoId;
}

void ResourceFactory::BindVAO(int vaoId)
{
	glBindVertexArray(vaoId);
}

void ResourceFactory::UnbindVAO()
{
	glBindVertexArray(0);
}

void ResourceFactory::AddDataToVAO(int attribList, int coordSize, std::vector<float> data)
{
	GLuint vboId = 0;
	glGenBuffers(1, &vboId);
	m_vboIds.push_back(vboId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data.front(), GL_STATIC_DRAW);
	glVertexAttribPointer(attribList, coordSize, GL_FLOAT, false, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	std::cout << "VAO buffer added to position " << attribList << " of size " << data.size() << std::endl;
}

void ResourceFactory::AddIndiciesToVAO(std::vector<int> indicies)
{
	GLuint vboId = 0;
	glGenBuffers(1, &vboId);
	m_vboIds.push_back(vboId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size() * sizeof(int), &indicies.front(), GL_STATIC_DRAW);
}

void ResourceFactory::LoadTerrain(const char * filename, int mapSize, Terrain ** terrain, TerrainTextures ** terrainTextures, glm::vec3 scale)
{
	std::ifstream file(filename, std::ios::binary);
	if (!file)
	{
		std::cerr << "Error loading terrain" << std::endl;
		return;
	}
	unsigned char * terrainData;
	if (mapSize > 0)
	{
		terrainData = new unsigned char[mapSize * mapSize];
	}
	else
	{
		return;
	}
	if (terrainData == NULL)
		return;
	file.seekg(0, std::ios::end);
	int length = file.tellg();
	file.seekg(0, std::ios::beg);
	file.read(reinterpret_cast<char *>(terrainData), length);
	file.close();

	(*terrain)->SetSize(mapSize);
	(*terrain)->SetTerrainData(terrainData);
	(*terrain)->SetScale(scale);

	std::vector<float> verts;
	std::vector<float> tex;
	std::vector<float> detailTex;
	std::vector<float> normals;
	std::vector<int> indicies;

	GLuint vaoId = CreateVAO();
	(*terrain)->SetVAOID(vaoId);
	BindVAO(vaoId);

	for(int z = 0; z < mapSize; z++)
		for (int x = 0; x < mapSize; x++)
		{
			int y = (*terrain)->GetHeight(x, z);
			verts.push_back(x);
			verts.push_back(y);
			verts.push_back(z);
			
			normals.push_back(0);
			normals.push_back(1);
			normals.push_back(0);
			tex.push_back((float)x / ((float)mapSize - 1));
			tex.push_back((float)z / ((float)mapSize - 1));
			detailTex.push_back((float)x);
			detailTex.push_back((float)z);
		}

	for(int z = 0; z < mapSize -1; z++)
		for (int x = 0; x < mapSize -1; x++)
		{
			indicies.push_back((z * mapSize + x));
			indicies.push_back(((z + 1) * mapSize) + x);
			indicies.push_back((z * mapSize) + x + 1);

			indicies.push_back((z * mapSize) + x + 1);
			indicies.push_back(((z + 1) * mapSize) + x);
			indicies.push_back(((z + 1) * mapSize) + x + 1);
		}

	(*terrain)->SetVertexCount(indicies.size());
	AddIndiciesToVAO(indicies);
	AddDataToVAO(0, 3, verts);
	AddDataToVAO(1, 2, tex);
	AddDataToVAO(2, 3, normals);
	AddDataToVAO(3, 2, detailTex);
	UnbindVAO();

	//Texture2D * terrainTexture = new Texture2D();
	//LoadTexture(texture, texSize, texSize, &terrainTexture);
	(*terrain)->SetTextures(terrainTextures);

}
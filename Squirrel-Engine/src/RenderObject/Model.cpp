#include "Model.h"
#include "FurStore.h"

unsigned int TextureFromFile(const char* path, const string& directory, bool gamma);

Model::Model(string const& path, bool gamma /*= false*/) : gammaCorrection(gamma)
{
	loadModel(path);
}

Model::~Model() {
	for (Mesh& obj : meshes)
		delete &obj;
	meshes.clear();
}

void Model::Draw(Shader& shader)
{
	shader.use();

	// Uniforms
	//Later there will be a iterator for all
	shader.setVec3("lightPos", vec3(0.0f));	//take it from light sources
	shader.setVec3("viewPos", camera->getPosition());	
	shader.setMat4("viewProjection", camera->getViewProjection());
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
	model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 1.0f));
	shader.setMat4("model",model);			//take it from transform component

	for (unsigned int i = 0; i < meshes.size(); i++)
		meshes[i].Draw(shader);
}

void Model::loadModel(string const& path)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
	
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
	{
		cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << endl;
		return;
	}
	
	directory = path.substr(0, path.find_last_of('/'));

	processNode(*scene->mRootNode, *scene);
}

void Model::processNode(aiNode& node, const aiScene& scene)
{
	for (unsigned int i = 0; i < node.mNumMeshes; i++)
	{
		aiMesh* mesh = scene.mMeshes[node.mMeshes[i]];
		meshes.push_back(*processMesh(*mesh, scene));
	}

	for (unsigned int i = 0; i < node.mNumChildren; i++)
	{
		processNode(*node.mChildren[i], scene);
	}
}

Mesh* Model::processMesh(aiMesh& mesh, const aiScene& scene)
{
	vector<s_Vertex> vertices;
	vector<unsigned int> indices;
	//vector<s_Texture> textures;
	
	for (unsigned int i = 0; i < mesh.mNumVertices; i++)
	{
		s_Vertex vertex;
		// positions
		glm::vec3 vector; 
		vector.x = mesh.mVertices[i].x;
		vector.y = mesh.mVertices[i].y;
		vector.z = mesh.mVertices[i].z;
		vertex.Position = vector;
		// normals
		if (mesh.HasNormals())
		{
			vector.x = mesh.mNormals[i].x;
			vector.y = mesh.mNormals[i].y;
			vector.z = mesh.mNormals[i].z;
			vertex.Normal = vector;
		}
		// texture coordinates
		if (mesh.mTextureCoords[0])
		{
			glm::vec2 vec;
			vec.x = mesh.mTextureCoords[0][i].x;
			vec.y = mesh.mTextureCoords[0][i].y;
			vertex.TexCoords = vec;
			// tangent
			vector.x = mesh.mTangents[i].x;
			vector.y = mesh.mTangents[i].y;
			vector.z = mesh.mTangents[i].z;
			vertex.Tangent = vector;
			// bitangent
			vector.x = mesh.mBitangents[i].x;
			vector.y = mesh.mBitangents[i].y;
			vector.z = mesh.mBitangents[i].z;
			vertex.Bitangent = vector;
		}
		else
			vertex.TexCoords = glm::vec2(0.0f, 0.0f);

		vertices.push_back(vertex);
	}
	// indices
	for (unsigned int i = 0; i < mesh.mNumFaces; i++)
	{
		aiFace face = mesh.mFaces[i];
		// retrieve all indices of the face and store them in the indices vector
		for (unsigned int j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}
	// process materials
	/*
	if (mesh.mMaterialIndex >= 0) {
		aiMaterial* material = scene.mMaterials[mesh.mMaterialIndex];

		// 1. diffuse maps
		vector<s_Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
		// 2. specular maps
		vector<s_Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
		// 3. normal maps
		std::vector<s_Texture> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
		textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
		// 4. height maps
		std::vector<s_Texture> heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
		textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());
	}
	*/
	return new Mesh(vertices, indices);
}

vector<s_Texture> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, const string typeName)
{
	vector<s_Texture> textures;
	for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
	{
		aiString str;
		mat->GetTexture(type, i, &str);
		// check if texture was loaded before and if so, continue to next iteration: skip loading a new texture
		bool skip = false;
		for (unsigned int j = 0; j < textures_loaded.size(); j++)
		{
			if (std::strcmp(textures_loaded[j].path.data(), str.C_Str()) == 0)
			{
				textures.push_back(textures_loaded[j]);
				skip = true; // a texture with the same filepath has already been loaded, continue to next one. (optimization)
				break;
			}
		}
		if (!skip)
		{   // if texture hasn't been loaded already, load it
			s_Texture texture;
			texture.id = TextureFromFile(str.C_Str(), this->directory);
			texture.type = typeName;
			texture.path = str.C_Str();
			textures.push_back(texture);
			textures_loaded.push_back(texture);  // store it as texture loaded for entire model, to ensure we won't unnecesery load duplicate textures.
		}
	}
	
	return textures;
}


static unsigned int TextureFromFile(const char* path, const string& directory, bool gamma)
{
	string filename = string(path);
	filename = directory + '/' + filename;

	unsigned int textureID;
	glGenTextures(1, &textureID);

	int width, height, nrComponents;
	unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
	if (data)
	{
		GLenum format;
		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else if (nrComponents == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);
	}
	else
	{
		std::cout << "Texture failed to load at path: " << path << std::endl;
		stbi_image_free(data);
	}

	return textureID;
}
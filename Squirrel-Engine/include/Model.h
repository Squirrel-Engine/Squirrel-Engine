#pragma once
#include <glad/glad.h> 

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

static unsigned int TextureFromFile(const char* path, const string& directory, bool gamma = false);

class Model
{
public:
	vector<s_Texture> textures_loaded;	// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
	vector<Mesh> meshes;
	string directory;
	bool gammaCorrection;

	Model(string const& path, bool gamma = false);

	void Draw(Shader& shader);

private:
	void loadModel(string const& path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);

	vector<s_Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);
};
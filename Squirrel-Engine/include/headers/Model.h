#pragma once
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>

#include "Mesh.h"
#include "TextureLoader.h"
#include "UniformDesc.h"

using namespace std;

class Model
{
public:
	Model(const string& path);

	void Draw(Shader& shader, TRANSFORM_DESC& uniformDesc);
	inline std::vector<Mesh>& getMeshes() { return meshes; }
private:
	vector<Mesh> meshes;
	string directory;

	void loadModel(const string& path);
	void processNode(aiNode& node, const aiScene& scene);
	Mesh processMesh(aiMesh& mesh, const aiScene& scene);
	Texture* loadMaterialTexture(aiMaterial* mat, aiTextureType type, bool isSRGB);
};

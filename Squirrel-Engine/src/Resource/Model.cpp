#include "Model.h"
#include "FurStore.h"
#include "InterfaceFactory.h"

Model::Model(const string& path)
{
	loadModel(path);
}

void Model::Draw(Shader& shader, TRANSFORM_DESC& uniformDesc)
{
	shader.use();
	// Uniforms
	//Later there will be a iterator for all
	shader.setVec3("viewPos", cameraDesc->viewPos);
	shader.setMat4("viewProjection", cameraDesc->viewProjection);
	shader.setMat4("model", uniformDesc.model);
	for (Actor* light : InterfaceFactory::getInstance().getGMInterface().levelStore->lights)
	{
		auto desc = dynamic_cast<LIGHT_DESC*>(light->componentList.at("lightComponent")->uniform);
		shader.setVec3("light.color", desc->lightColor);
		shader.setVec3("light.position", desc->lightPos);
		shader.setFloat("light.constant", desc->constant);
		shader.setFloat("light.linear", desc->linear);
		shader.setFloat("light.quadratic", desc->quadratic);
	}

	for (unsigned int i = 0; i < meshes.size(); i++) {
		meshes[i].m_Material.BindMaterialInformation(&shader);
		meshes[i].Draw();
	}
}

void Model::loadModel(const string& path)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(
		path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

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
		meshes.push_back(processMesh(*mesh, scene));
	}

	for (unsigned int i = 0; i < node.mNumChildren; i++)
	{
		processNode(*node.mChildren[i], scene);
	}
}

Mesh Model::processMesh(aiMesh& mesh, const aiScene& scene)
{
	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec3> tangents;
	std::vector<glm::vec3> bitangents;
	std::vector<unsigned int> indices;

	positions.reserve(mesh.mNumVertices);
	uvs.reserve(mesh.mNumVertices);
	normals.reserve(mesh.mNumVertices);
	tangents.reserve(mesh.mNumVertices);
	bitangents.reserve(mesh.mNumVertices);
	indices.reserve(mesh.mNumFaces * 3);

	// Process vertices
	for (unsigned int i = 0; i < mesh.mNumVertices; ++i) {
		glm::vec2 uvCoord;
		// Texture Coordinates (check if there is texture coordinates)
		if (mesh.mTextureCoords[0]) {
			// A vertex can contain up to 8 different texture coordinates. We are just going to use one set of TexCoords per vertex so grab the first one
			uvCoord.x = mesh.mTextureCoords[0][i].x;
			uvCoord.y = mesh.mTextureCoords[0][i].y;
		}
		else {
			uvCoord.x = 0.0f;
			uvCoord.y = 0.0f;
		}

		positions.push_back(glm::vec3(mesh.mVertices[i].x, mesh.mVertices[i].y, mesh.mVertices[i].z));
		uvs.push_back(glm::vec2(uvCoord.x, uvCoord.y));
		normals.push_back(glm::vec3(mesh.mNormals[i].x, mesh.mNormals[i].y, mesh.mNormals[i].z));
		tangents.push_back(glm::vec3(mesh.mTangents[i].x, mesh.mTangents[i].y, mesh.mTangents[i].z));
		bitangents.push_back(glm::vec3(mesh.mBitangents[i].x, mesh.mBitangents[i].y, mesh.mBitangents[i].z));
	}

	// Process Indices
	// Loop through every face (triangle thanks to aiProcess_Triangulate) and stores its indices in our meshes indices. This will ensure they are in the right order.
	for (unsigned int i = 0; i < mesh.mNumFaces; ++i) {
		aiFace face = mesh.mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; ++j) {
			indices.push_back(face.mIndices[j]);
		}
	}

	Mesh newMesh(positions, uvs, normals, tangents, bitangents, indices);
	newMesh.LoadData();

	// Process Materials (textures in this case)
	if (mesh.mMaterialIndex >= 0) {
		aiMaterial* material = scene.mMaterials[mesh.mMaterialIndex];

		newMesh.m_Material.setAlbedoMap(loadMaterialTexture(material, aiTextureType_DIFFUSE, true));
		newMesh.m_Material.setNormalMap(loadMaterialTexture(material, aiTextureType_NORMALS, false));
		newMesh.m_Material.setAmbientOcclusionMap(loadMaterialTexture(material, aiTextureType_AMBIENT, false));
		newMesh.m_Material.setDisplacementMap(loadMaterialTexture(material, aiTextureType_DISPLACEMENT, true));
	}

	return newMesh;
}

Texture* Model::loadMaterialTexture(aiMaterial* mat, aiTextureType type, bool isSRGB) {
	// Log material constraints are being violated (1 texture per type for the standard shader)
	if (mat->GetTextureCount(type) > 1)
		cout << "Mesh's default material contains more than 1 texture for the same type, which currently isn't supported by the standard shader" << endl;

	// Load the texture of a certain type, assuming there is one
	if (mat->GetTextureCount(type) > 0) {
		aiString str;
		mat->GetTexture(type, 0, &str); // Grab only the first texture (standard shader only supports one texture of each type, it doesn't know how you want to do special blending)

		// Assumption made: material stuff is located in the same directory as the model object
		std::string fileToSearch = (directory + "/" + std::string(str.C_Str())).c_str();

		TextureSettings textureSettings;
		textureSettings.IsSRGB = isSRGB;
		return TextureLoader::load2DTexture(fileToSearch, &textureSettings);
	}

	return nullptr;
}
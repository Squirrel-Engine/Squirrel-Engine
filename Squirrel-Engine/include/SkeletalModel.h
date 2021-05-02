#pragma once
#include "glad/glad.h"
#include "SkeletalMesh.h"
#include <vector>
#include "GLFW/glfw3.h"
#include <string>
#include <map>
#include "glm\gtc\quaternion.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "assimp\Importer.hpp"
#include "assimp\scene.h"
#include "assimp\postprocess.h"



using namespace std;

class SkeletalModel
{
public:
	SkeletalModel(const string& path);
	~SkeletalModel();
	static const unsigned int MAX_BONES = 100;


	void initShaders(GLuint shader_program);
	void loadModel(const string& path);
	void draw(GLuint shaders_program);
	void showNodeName(aiNode* node);

	glm::mat4 aiToGlm(aiMatrix4x4 ai_matr);
	aiQuaternion nlerp(aiQuaternion a, aiQuaternion b, float blend); // super super n lerp =)

private:
	Assimp::Importer import;
	const aiScene* scene;
	vector<SkeletalMesh> meshes; // one mesh in one object
	string directory;

	map<string, unsigned int> m_bone_mapping; // maps a bone name and their index
	unsigned int m_num_bones = 0;
	vector<BoneMatrix> m_bone_matrices;
	aiMatrix4x4 m_global_inverse_transform;

	GLuint m_bone_location[MAX_BONES];
	float ticks_per_second = 0.0f;

	void processNode(aiNode* node, const aiScene* scene);
	SkeletalMesh processMesh(aiMesh* mesh, const aiScene* scene);
	vector<Texture> LoadMaterialTexture(aiMaterial* mat, aiTextureType type, string type_name);


	unsigned int findPosition(float p_animation_time, const aiNodeAnim* p_node_anim);
	unsigned int findRotation(float p_animation_time, const aiNodeAnim* p_node_anim);
	unsigned int findScaling(float p_animation_time, const aiNodeAnim* p_node_anim);
	const aiNodeAnim* findNodeAnim(const aiAnimation* p_animation, const string p_node_name);
	// calculate transform matrix
	aiVector3D calcInterpolatedPosition(float p_animation_time, const aiNodeAnim* p_node_anim);
	aiQuaternion calcInterpolatedRotation(float p_animation_time, const aiNodeAnim* p_node_anim);
	aiVector3D calcInterpolatedScaling(float p_animation_time, const aiNodeAnim* p_node_anim);

	void readNodeHierarchy(float p_animation_time, const aiNode* p_node, const aiMatrix4x4 parent_transform);
	void boneTransform(double time_in_sec, vector<aiMatrix4x4>& transforms);

	// rotate Head
	glm::quat rotate_head_xz = glm::quat(cos(glm::radians(0.0f)), sin(glm::radians(0.0f)) * glm::vec3(1.0f, 0.0f, 0.0f)); // this quad do nothingggggg!!!!!

};


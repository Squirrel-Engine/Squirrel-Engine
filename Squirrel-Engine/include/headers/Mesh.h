#pragma once
#include "Shader.h"
#include "Material.h"

#include <string>
#include <vector>
using namespace std;
class Model;

class Mesh
{
	friend Model;
public:
	Mesh();
	Mesh(std::vector<glm::vec3>& positions, std::vector<unsigned int>& indices);
	Mesh(std::vector<glm::vec3>& positions, std::vector<glm::vec2>& uvs, std::vector<unsigned int>& indices);
	Mesh(std::vector<glm::vec3>& positions, std::vector<glm::vec2>& uvs, std::vector<glm::vec3>& normals, std::vector<unsigned int>& indices);
	Mesh(std::vector<glm::vec3>& positions, std::vector<glm::vec2>& uvs, std::vector<glm::vec3>& normals, std::vector<glm::vec3>& tangents, std::vector<glm::vec3>& bitangents, std::vector<unsigned int>& indices);
	~Mesh() {}

	void Draw();
	void LoadData(bool interleaved = true);
	inline Material& getMaterial() { return m_Material; }
protected:
	unsigned int m_VAO, m_VBO, m_IBO;
	Material m_Material;

	std::vector<glm::vec3> m_Positions;
	std::vector<glm::vec2> m_UVs;
	std::vector<glm::vec3> m_Normals;
	std::vector<glm::vec3> m_Tangents;
	std::vector<glm::vec3> m_Bitangents;

	std::vector<unsigned int> m_Indices;
};

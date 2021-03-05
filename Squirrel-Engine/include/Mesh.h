#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"
#include "Material.h"

#include <string>
#include <vector>
using namespace std;

struct s_Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
	glm::vec3 Tangent;
	glm::vec3 Bitangent;
};

class Mesh {
public:
	vector<s_Vertex>		vertices;
	vector<unsigned int>	indices;
	Material				material;
	unsigned int VAO;

	Mesh(vector<s_Vertex>& vertices, vector<unsigned int>& indices, vector<s_Texture>& textures);

	void Draw(std::shared_ptr<Shader>& shader);

private:
	unsigned int VBO, EBO;
	void setupMesh();
};
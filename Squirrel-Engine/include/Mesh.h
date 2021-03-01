#pragma once
#include <glad/glad.h>m
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"

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

struct s_Texture {
	unsigned int id;
	string type;
	string path;
};

class Mesh {
public:
	vector<s_Vertex>       vertices;
	vector<unsigned int>	indices;
	vector<s_Texture>      textures;
	unsigned int VAO;

	Mesh(vector<s_Vertex>& vertices, vector<unsigned int>& indices, vector<s_Texture>& textures);

	void Draw(std::shared_ptr<Shader>& shader);

private:
	unsigned int VBO, EBO;
	void setupMesh();
};
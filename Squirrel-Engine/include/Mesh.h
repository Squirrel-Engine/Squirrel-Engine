#pragma once

#include <glad/glad.h>m
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"

#include <string>
#include <vector>
using namespace std;

struct s_Vertex {
	// position
	glm::vec3 Position;
	// normal
	glm::vec3 Normal;
	// texCoords
	glm::vec2 TexCoords;
	// tangent
	glm::vec3 Tangent;
	// bitangent
	glm::vec3 Bitangent;
};

struct s_Texture {
	unsigned int id;
	string type;
	string path;
};

class Mesh {
public:
	// mesh Data
	vector<s_Vertex>       vertices;
	vector<unsigned int> indices;
	vector<s_Texture>      textures;
	unsigned int VAO;

	// constructor
	Mesh(vector<s_Vertex> vertices, vector<unsigned int> indices, vector<s_Texture> textures);

	// render the mesh
	void Draw(std::shared_ptr<Shader> shader);

private:
	// render data 
	unsigned int VBO, EBO;

	// initializes all the buffer objects/arrays
	void setupMesh();
};
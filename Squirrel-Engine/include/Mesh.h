#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"
#include "Material.h"

#include <string>
#include <vector>
using namespace std;

struct s_Vertex
{
	vec3 Position;
	vec3 Normal;
	vec2 TexCoords;
	vec3 Tangent;
	vec3 Bitangent;
};

class Mesh
{
public:
	vector<s_Vertex> vertices;
	vector<unsigned int> indices;
	Material material;
	unsigned int VAO;

	Mesh(vector<s_Vertex>& vertices, vector<unsigned int>& indices);
	~Mesh();

	void Draw(Shader& shader);
private:
	unsigned int VBO, EBO;
	void setupMesh();
};

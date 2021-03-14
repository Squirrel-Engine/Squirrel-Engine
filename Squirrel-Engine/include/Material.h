#pragma once
#include <string>
#include <vector>
#include "Shader.h"
#include "Texture.h"
using namespace std;

struct s_Texture {
	unsigned int id;
	string type;
	string path;
};

class Material
{
public:
	Material();

	vector<s_Texture> textures;
	glm::vec4 color;
	//normal strength
	//roughness power
	//metalic power
public:
	void setup();
	void setInt(int value);
	void setFloat(float value);
	void setColor(glm::vec4 color);
	void setTexture(string typeName, const std::string& path);
};
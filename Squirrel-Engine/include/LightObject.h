#pragma once
#include "Shader.h"
#include "UniformDesc.h"

class LightObject {
private:
	unsigned int VBO;
public:
	LightObject();
	~LightObject();

	void Draw(Shader& shader, TRANSFORM_DESC& transformUniform, LIGHT_DESC& lightUniform);
public:
	unsigned int lightCubeVAO;
};

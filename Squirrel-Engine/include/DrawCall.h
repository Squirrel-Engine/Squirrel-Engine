#pragma once
#include "Shader.h"
#include "Texture.h"
#include "UniformDesc.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Model.h"

class DrawCall
{
public:
	DrawCall() {};

public:
	virtual void draw() = 0;
};


#pragma once
#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "UniformDesc.h"
#include "LightObject.h"

class DrawCall
{
public:
	DrawCall()
	{
	};

public:
	virtual void draw() = 0;
};

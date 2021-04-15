#pragma once
#include "Shader.h"
#include "UniformDesc.h"
#include "DrawCall.h"

class LightDrawCall : public DrawCall{
public:
	LightDrawCall(Shader* shader, Squirrel::LIGHT_DESC* uniformDesc);

	void draw() override;
public:
	Shader* shader;
	Squirrel::LIGHT_DESC* uniformDesc;
};
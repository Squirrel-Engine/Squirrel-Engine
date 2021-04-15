#pragma once
#include "Shader.h"
#include "UniformDesc.h"
#include "DrawCall.h"
#include "FurStore.h"
#include "Light.h"

class LightDrawCall : public DrawCall{
public:
	LightDrawCall(Squirrel::Light* light, Shader* shader, Squirrel::TRANSFORM_DESC* transformUniform, Squirrel::LIGHT_DESC* lightUniform);

	void draw() override;
public:
	Squirrel::Light* light;
	Shader* shader;
	Squirrel::TRANSFORM_DESC* transformUniform;
	Squirrel::LIGHT_DESC* lightUniform;
};
#pragma once
#include "Shader.h"
#include "UniformDesc.h"
#include "DrawCall.h"
#include "FurStore.h"
#include "LightObject.h"

class LightDrawCall : public DrawCall{
public:
	LightDrawCall(LightObject* light, Shader* shader, TRANSFORM_DESC* transformUniform, LIGHT_DESC* lightUniform);

	void draw() override;
public:
	LightObject* light;
	Shader* shader;
	TRANSFORM_DESC* transformUniform;
	LIGHT_DESC* lightUniform;
};
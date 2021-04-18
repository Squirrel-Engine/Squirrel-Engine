#pragma once
#include "Macros.h"
#include <iostream>
#include "../../Squirrel-Engine/include/LightObject.h"
#include "../../Squirrel-Engine/include/InterfaceFactory.h"
#include "../../Squirrel-Engine/include/LightDrawCall.h"
#include "Components/TransformComponent.h"

SR_COMPONENT()

class LightComponent : public ActorComponent
{
private:
	int shaderID;
	LightObject light;
public:
	SR_VAR_START()
	vec3 color;
	SR_VAR_END()

public:
	LightComponent();
	void BeginPlay() override;
	void Update() override;
	void setup() override;

	void setColor(float r, float g, float b);

private:
	int getShaderID() { return shaderID; }
};

SR_COMPONENT()

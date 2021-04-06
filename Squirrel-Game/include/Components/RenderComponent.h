#pragma once
#include "Macros.h"
#include <vector>
#include "../../../Squirrel-Engine/include/ActorComponent.h"
#include "Components/TransformComponent.h"

SR_COMPONENT()
class RenderComponent : public Squirrel::ActorComponent
{
public:
	RenderComponent();
	void BeginPlay() override;
	void Update() override;
	void setup();

	int shaderID;
	int modelID;
	std::vector<int> materials;
	SR_VAR_START()
	int C_ModelID;
	
	int C_MaterialID_0;
	int C_MaterialID_1;
	int C_MaterialID_2;
	int C_MaterialID_3;
	int C_MaterialID_4;
	int C_MaterialID_5;
	int C_MaterialID_6;
	int C_MaterialID_7;
	int C_MaterialID_8;
	int C_MaterialID_9;
	int C_MaterialID_10;
	int C_MaterialID_11;
	int C_MaterialID_12;
	int C_MaterialID_13;
	int C_MaterialID_14;
	int C_MaterialID_15;

	int C_ShaderID;
	SR_VAR_END()
};
SR_COMPONENT()
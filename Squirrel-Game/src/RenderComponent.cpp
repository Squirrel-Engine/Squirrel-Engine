#include "Components/RenderComponent.h"
#include "../../Squirrel-Engine/include/InterfaceFactory.h"



RenderComponent::RenderComponent()
{

}


void RenderComponent::BeginPlay()
{
	
}

void RenderComponent::Update()
{
	DrawCall* drawCall = new DrawCall(Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID),
		Squirrel::InterfaceFactory::getInstance().getRMInterface().getShader(shaderID));
	Squirrel::InterfaceFactory::getInstance().getRDInterface().submitDrawCall(drawCall);

	//float x = getComponent<TransformComponent*>("transformComponent")->getTransform().x;
}

void RenderComponent::setup()
{
	modelID = C_ModelID;
	shaderID = C_ShaderID;

	int size = Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID).meshes.size();

	switch (size)
	{
	case 1:
		materials.push_back(C_MaterialID_1);
		break;
	case 2:
		materials.push_back(C_MaterialID_1);
		materials.push_back(C_MaterialID_2);
		break;
	case 3:
		materials.push_back(C_MaterialID_1);
		materials.push_back(C_MaterialID_2);
		materials.push_back(C_MaterialID_3);
		break;
	case 4:
		materials.push_back(C_MaterialID_1);
		materials.push_back(C_MaterialID_2);
		materials.push_back(C_MaterialID_3);
		materials.push_back(C_MaterialID_4);
		break;
	case 5:
		materials.push_back(C_MaterialID_1);
		materials.push_back(C_MaterialID_2);
		materials.push_back(C_MaterialID_3);
		materials.push_back(C_MaterialID_4);
		materials.push_back(C_MaterialID_5);
		break;
	case 6:
		materials.push_back(C_MaterialID_1);
		materials.push_back(C_MaterialID_2);
		materials.push_back(C_MaterialID_3);
		materials.push_back(C_MaterialID_4);
		materials.push_back(C_MaterialID_5);
		materials.push_back(C_MaterialID_6);
		break;
	case 7:
		materials.push_back(C_MaterialID_1);
		materials.push_back(C_MaterialID_2);
		materials.push_back(C_MaterialID_3);
		materials.push_back(C_MaterialID_4);
		materials.push_back(C_MaterialID_5);
		materials.push_back(C_MaterialID_6);
		materials.push_back(C_MaterialID_7);
		break;
	default:
		break;
	}
}

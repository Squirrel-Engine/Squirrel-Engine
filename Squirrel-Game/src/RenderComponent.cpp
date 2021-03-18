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
	auto drawCall = new DrawCall(Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID), 
									  Squirrel::InterfaceFactory::getInstance().getRMInterface().getShader(shaderID));

	Squirrel::InterfaceFactory::getInstance().getRDInterface().submitDrawCall(*drawCall);
}

void RenderComponent::setup()
{
	modelID = C_ModelID;
	shaderID = C_ShaderID;

	int size = Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID)->meshes.size();

	switch (size)
	{
	case 1:
		materials.push_back(C_MaterialID_0);
		Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID)->meshes.at(0).material = *Squirrel::InterfaceFactory::getInstance().getRMInterface().getMaterial(materials[0]);
		break;
	case 2:
		materials.push_back(C_MaterialID_0);
		Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID)->meshes.at(0).material = *Squirrel::InterfaceFactory::getInstance().getRMInterface().getMaterial(materials[0]);
		materials.push_back(C_MaterialID_1);
		Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID)->meshes.at(1).material = *Squirrel::InterfaceFactory::getInstance().getRMInterface().getMaterial(materials[1]);
		break;
	case 3:
		materials.push_back(C_MaterialID_0);
		Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID)->meshes.at(0).material = *Squirrel::InterfaceFactory::getInstance().getRMInterface().getMaterial(materials[0]);
		materials.push_back(C_MaterialID_1);
		Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID)->meshes.at(1).material = *Squirrel::InterfaceFactory::getInstance().getRMInterface().getMaterial(materials[1]);
		materials.push_back(C_MaterialID_2);
		Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID)->meshes.at(2).material = *Squirrel::InterfaceFactory::getInstance().getRMInterface().getMaterial(materials[2]);
		break;
	case 4:
		materials.push_back(C_MaterialID_0);
		Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID)->meshes.at(0).material = *Squirrel::InterfaceFactory::getInstance().getRMInterface().getMaterial(materials[0]);
		materials.push_back(C_MaterialID_1);
		Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID)->meshes.at(1).material = *Squirrel::InterfaceFactory::getInstance().getRMInterface().getMaterial(materials[1]);
		materials.push_back(C_MaterialID_2);
		Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID)->meshes.at(2).material = *Squirrel::InterfaceFactory::getInstance().getRMInterface().getMaterial(materials[2]);
		materials.push_back(C_MaterialID_3);
		Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID)->meshes.at(3).material = *Squirrel::InterfaceFactory::getInstance().getRMInterface().getMaterial(materials[3]);
		break;
	default:
		break;
	}

	

	
}

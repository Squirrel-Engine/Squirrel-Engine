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
	auto drawCall = new ModelDrawCall(Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID),
									  Squirrel::InterfaceFactory::getInstance().getRMInterface().getShader(shaderID),
								      dynamic_cast<Squirrel::TRANSFORM_DESC*>(getComponent<TransformComponent*>("transformComponent")->uniform));

	Squirrel::InterfaceFactory::getInstance().getRDInterface().submitDrawCall(*drawCall);
}

void RenderComponent::setup()
{
	modelID = C_ModelID;
	shaderID = C_ShaderID;

	int size = Squirrel::getInterface<Squirrel::RM_Interface>().getMesh(modelID)->meshes.size();
	std::cout << "Size: " << size << std::endl;
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
	case 9:
		materials.push_back(C_MaterialID_0);
		Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID)->meshes.at(0).material = *Squirrel::InterfaceFactory::getInstance().getRMInterface().getMaterial(materials[0]);
		materials.push_back(C_MaterialID_1);
		Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID)->meshes.at(1).material = *Squirrel::InterfaceFactory::getInstance().getRMInterface().getMaterial(materials[1]);
		materials.push_back(C_MaterialID_2);
		Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID)->meshes.at(2).material = *Squirrel::InterfaceFactory::getInstance().getRMInterface().getMaterial(materials[2]);
		materials.push_back(C_MaterialID_3);
		Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID)->meshes.at(3).material = *Squirrel::InterfaceFactory::getInstance().getRMInterface().getMaterial(materials[3]);
		materials.push_back(C_MaterialID_4);
		Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID)->meshes.at(4).material = *Squirrel::InterfaceFactory::getInstance().getRMInterface().getMaterial(materials[4]);
		materials.push_back(C_MaterialID_5);
		Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID)->meshes.at(5).material = *Squirrel::InterfaceFactory::getInstance().getRMInterface().getMaterial(materials[5]);
		materials.push_back(C_MaterialID_6);
		Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID)->meshes.at(6).material = *Squirrel::InterfaceFactory::getInstance().getRMInterface().getMaterial(materials[6]);
		materials.push_back(C_MaterialID_7);
		Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID)->meshes.at(7).material = *Squirrel::InterfaceFactory::getInstance().getRMInterface().getMaterial(materials[7]);
		materials.push_back(C_MaterialID_8);
		Squirrel::InterfaceFactory::getInstance().getRMInterface().getMesh(modelID)->meshes.at(8).material = *Squirrel::InterfaceFactory::getInstance().getRMInterface().getMaterial(materials[8]);
		break;
	default:
		break;
	}

	

	
}

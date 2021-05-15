#include "Components/RenderComponent.h"

RenderComponent::RenderComponent()
{
}


void RenderComponent::BeginPlay()
{

}

void RenderComponent::Update()
{
	auto drawCall = new ModelDrawCall(getInterface<RM_Interface>().getMesh(modelID),
	                                  getInterface<RM_Interface>().getShader(shaderID),
	                                  dynamic_cast<TRANSFORM_DESC*>(getComponent<TransformComponent>()->uniform));

	getInterface<RD_Interface>().submitDrawCall(*drawCall);
}

void RenderComponent::setup()
{
	modelID = C_ModelID;
	shaderID = C_ShaderID;
	/*
	int size = getInterface<RM_Interface>().getMesh(modelID)->meshes.size();
	std::cout << "Size: " << size << std::endl;
	switch (size)
	{
	case 1:
		materials.push_back(C_MaterialID_0);
		getInterface<RM_Interface>().getMesh(modelID)->meshes.at(0).material = *getInterface<RM_Interface>().getMaterial(materials[0]);
		break;
	case 2:
		materials.push_back(C_MaterialID_0);
		getInterface<RM_Interface>().getMesh(modelID)->meshes.at(0).material = *getInterface<RM_Interface>().getMaterial(materials[0]);
		materials.push_back(C_MaterialID_1);
		getInterface<RM_Interface>().getMesh(modelID)->meshes.at(1).material = *getInterface<RM_Interface>().getMaterial(materials[1]);
		break;
	case 3:
		materials.push_back(C_MaterialID_0);
		getInterface<RM_Interface>().getMesh(modelID)->meshes.at(0).material = *getInterface<RM_Interface>().getMaterial(materials[0]);
		materials.push_back(C_MaterialID_1);
		getInterface<RM_Interface>().getMesh(modelID)->meshes.at(1).material = *getInterface<RM_Interface>().getMaterial(materials[1]);
		materials.push_back(C_MaterialID_2);
		getInterface<RM_Interface>().getMesh(modelID)->meshes.at(2).material = *getInterface<RM_Interface>().getMaterial(materials[2]);
		break;
	case 4:
		materials.push_back(C_MaterialID_0);
		getInterface<RM_Interface>().getMesh(modelID)->meshes.at(0).material = *getInterface<RM_Interface>().getMaterial(materials[0]);
		materials.push_back(C_MaterialID_1);
		getInterface<RM_Interface>().getMesh(modelID)->meshes.at(1).material = *getInterface<RM_Interface>().getMaterial(materials[1]);
		materials.push_back(C_MaterialID_2);
		getInterface<RM_Interface>().getMesh(modelID)->meshes.at(2).material = *getInterface<RM_Interface>().getMaterial(materials[2]);
		materials.push_back(C_MaterialID_3);
		getInterface<RM_Interface>().getMesh(modelID)->meshes.at(3).material = *getInterface<RM_Interface>().getMaterial(materials[3]);
		break;
	case 9:
		materials.push_back(C_MaterialID_0);
		getInterface<RM_Interface>().getMesh(modelID)->meshes.at(0).material = *getInterface<RM_Interface>().getMaterial(materials[0]);
		materials.push_back(C_MaterialID_1);
		getInterface<RM_Interface>().getMesh(modelID)->meshes.at(1).material = *getInterface<RM_Interface>().getMaterial(materials[1]);
		materials.push_back(C_MaterialID_2);
		getInterface<RM_Interface>().getMesh(modelID)->meshes.at(2).material = *getInterface<RM_Interface>().getMaterial(materials[2]);
		materials.push_back(C_MaterialID_3);
		getInterface<RM_Interface>().getMesh(modelID)->meshes.at(3).material = *getInterface<RM_Interface>().getMaterial(materials[3]);
		materials.push_back(C_MaterialID_4);
		getInterface<RM_Interface>().getMesh(modelID)->meshes.at(4).material = *getInterface<RM_Interface>().getMaterial(materials[4]);
		materials.push_back(C_MaterialID_5);
		getInterface<RM_Interface>().getMesh(modelID)->meshes.at(5).material = *getInterface<RM_Interface>().getMaterial(materials[5]);
		materials.push_back(C_MaterialID_6);
		getInterface<RM_Interface>().getMesh(modelID)->meshes.at(6).material = *getInterface<RM_Interface>().getMaterial(materials[6]);
		materials.push_back(C_MaterialID_7);
		getInterface<RM_Interface>().getMesh(modelID)->meshes.at(7).material = *getInterface<RM_Interface>().getMaterial(materials[7]);
		materials.push_back(C_MaterialID_8);
		getInterface<RM_Interface>().getMesh(modelID)->meshes.at(8).material = *getInterface<RM_Interface>().getMaterial(materials[8]);
		break;
	default:
		break;
	}
	*/
}

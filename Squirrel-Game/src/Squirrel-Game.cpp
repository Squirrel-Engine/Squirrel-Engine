// Squirrel-Engine.cpp : Defines the entry point for the application.
//
#include "Skeleton.h"
#include "../Squirrel-Engine/include/Squirrel.h"
#include "../../Squirrel-Engine/include/Mesh.h"
#include "Components/RenderComponent.h"

class Sandbox : public Squirrel::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

	virtual void Run() override;
};

Squirrel::Application* Squirrel::CreateApplication()
{
	return new Sandbox();
}

void Sandbox::Run()
{
	Skeleton* skeleton = new Skeleton();
	skeleton->health = 0;
	skeleton->attackPower = 0;
	
	TransformComponent* transformComponent = new TransformComponent();
	
	transformComponent->setup();
	
	transformComponent->setParent(skeleton);
	skeleton->transformComponent = transformComponent;
	skeleton->insertComponent("transformComponent", transformComponent);


	
	RenderComponent* renderComponent = new RenderComponent();
	
	renderComponent->C_ModelID = 0;
	renderComponent->C_MaterialID_1 = 0;
	renderComponent->C_ShaderID = 0;
	renderComponent->setup();
	
	renderComponent->setParent(skeleton);
	skeleton->renderComponent = renderComponent;
	skeleton->insertComponent("renderComponent", renderComponent);


	Squirrel::InterfaceFactory::getInstance().getGMInterface().levelStore->spawnNewActor(skeleton);

}
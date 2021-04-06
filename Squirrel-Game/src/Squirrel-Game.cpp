// Squirrel-Engine.cpp : Defines the entry point for the application.
//
#include "Skeleton.h"
#include "../Squirrel-Engine/include/Squirrel.h"
#include "../../Squirrel-Engine/include/Mesh.h"
#include "Components/RenderComponent.h"
#include "Components/CameraComponent.h"
#include <include/Camera.h>

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
	///////
	Camera* camera = new Camera();

	TransformComponent* transformComponent1 = new TransformComponent();
	transformComponent1->setup();
	transformComponent1->setParent(camera);
	camera->transformComponent = transformComponent1;
	camera->transformComponent->setTransform(glm::vec3(0, 0, 0));
	camera->insertComponent("transformComponent", transformComponent1);

	CameraComponent* cameraComponent = new CameraComponent();
	cameraComponent->setup();
	cameraComponent->setParent(camera);
	camera->cameraComponent = cameraComponent;
	camera->insertComponent("cameraComponent", cameraComponent);
	//////

	Skeleton* skeleton = new Skeleton();
	skeleton->health = 0;
	skeleton->attackPower = 0;
	
	TransformComponent* transformComponent = new TransformComponent();
	transformComponent->setup();
	transformComponent->setParent(skeleton);
	skeleton->transformComponent = transformComponent;
	skeleton->transformComponent->setTransform(glm::vec3(1.7, 0, -30));
	skeleton->transformComponent->setRotation(glm::vec3(-1.0f, -1.0f, 10.0f));
	skeleton->insertComponent("transformComponent", transformComponent);

	RenderComponent* renderComponent = new RenderComponent();
	renderComponent->C_ModelID = 0;
	renderComponent->C_MaterialID_0 = 0;
	renderComponent->C_MaterialID_1 = 1;
	renderComponent->C_ShaderID = 0;
	renderComponent->setup();
	renderComponent->setParent(skeleton);
	skeleton->renderComponent = renderComponent;
	skeleton->insertComponent("renderComponent", renderComponent);

	//////////////////
	Squirrel::InterfaceFactory::getInstance().getGMInterface().levelStore->spawnNewCamera(camera);
	Squirrel::InterfaceFactory::getInstance().getGMInterface().levelStore->spawnNewActor(skeleton);
}
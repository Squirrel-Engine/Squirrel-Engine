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
	/////
	Camera* mainCamera = new Camera();

	TransformComponent* camera_transformComponent = new TransformComponent();
	//camera_transformComponent->setTransform(glm::vec3(0, 0, 0));
	camera_transformComponent->setParent(mainCamera);
	mainCamera->transformComponent = camera_transformComponent;
	mainCamera->transformComponent->setup();
	mainCamera->insertComponent("transformComponent", camera_transformComponent);

	CameraComponent* camera_cameraComponent = new CameraComponent();
	camera_cameraComponent->setParent(mainCamera);
	mainCamera->cameraComponent = camera_cameraComponent;
	mainCamera->cameraComponent->setup();
	mainCamera->insertComponent("cameraComponent", camera_cameraComponent);
	/////
	/////
	Skeleton* skeleton = new Skeleton();
	skeleton->health = 100;
	skeleton->attackPower = 50;
	
	TransformComponent* skeleton_transformComponent = new TransformComponent();
	skeleton_transformComponent->setTransform(glm::vec3(0, 0, -30));
	skeleton_transformComponent->setRotation(glm::vec3(20, 20, 20));
	skeleton_transformComponent->setParent(skeleton);
	skeleton->transformComponent = skeleton_transformComponent;
	skeleton->transformComponent->setup();
	skeleton->insertComponent("transformComponent", skeleton_transformComponent);

	RenderComponent* skeleton_renderComponent = new RenderComponent();
	skeleton_renderComponent->C_ModelID = 0;
	skeleton_renderComponent->C_MaterialID_0 = 0;
	skeleton_renderComponent->C_MaterialID_1 = 1;
	skeleton_renderComponent->C_ShaderID = 0;
	skeleton_renderComponent->setParent(skeleton);
	skeleton->renderComponent = skeleton_renderComponent;
	skeleton->renderComponent->setup();
	skeleton->insertComponent("renderComponent", skeleton_renderComponent);
	/////

	Squirrel::InterfaceFactory::getInstance().getGMInterface().levelStore->spawnNewCamera(mainCamera);
	Squirrel::InterfaceFactory::getInstance().getGMInterface().levelStore->spawnNewActor(skeleton);
}
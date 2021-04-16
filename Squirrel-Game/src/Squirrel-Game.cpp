// Squirrel-Engine.cpp : Defines the entry point for the application.
//
#include "Squirrel-Game.h"

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
	TestControlSchema* testSchema = new TestControlSchema();
	Squirrel::InterfaceFactory::getInstance().getIPInterface().setControlSchema(testSchema);
	/////
	Camera* mainCamera = new Camera();

	TransformComponent* camera_transformComponent = new TransformComponent();
	//camera_transformComponent->setTransform(glm::vec3(0, 30, 0));
	camera_transformComponent->setParent(mainCamera);
	mainCamera->transformComponent = camera_transformComponent;
	mainCamera->insertComponent("transformComponent", camera_transformComponent);

	CameraComponent* camera_cameraComponent = new CameraComponent();
	camera_cameraComponent->setParent(mainCamera);
	mainCamera->cameraComponent = camera_cameraComponent;
	mainCamera->insertComponent("cameraComponent", camera_cameraComponent);


	Skeleton* skeleton = new Skeleton();

	/////
	skeleton->transformComponent->setTransform(glm::vec3(0, 0, -30));
	skeleton->transformComponent->setRotation(glm::vec3(20, 20, 20));

	skeleton->renderComponent->C_ModelID = 0;
	skeleton->renderComponent->C_MaterialID_0 = 0;
	skeleton->renderComponent->C_MaterialID_1 = 1;
	skeleton->renderComponent->C_ShaderID = 0;

 

	Squirrel::InterfaceFactory::getInstance().getGMInterface().levelStore->spawnNewCamera(mainCamera);


	Squirrel::InterfaceFactory::getInstance().getGMInterface().levelStore->spawnNewActor(skeleton);


}
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

	/////
	skeleton->transformComponent->setTransform(glm::vec3(0, 0, -30));
	skeleton->transformComponent->setRotation(glm::vec3(20, 20, 20));


	Skeleton* skeleton1 = new Skeleton();

	/////
	skeleton1->transformComponent->setTransform(glm::vec3(0, 10, -50));
	skeleton1->transformComponent->setRotation(glm::vec3(-20, -20, -20));

	Squirrel::InterfaceFactory::getInstance().getGMInterface().levelStore->spawnNewCamera(mainCamera);


	Squirrel::InterfaceFactory::getInstance().getGMInterface().levelStore->spawnNewActor(skeleton);

	//Squirrel::InterfaceFactory::getInstance().getGMInterface().levelStore->spawnNewActor(skeleton1);

}
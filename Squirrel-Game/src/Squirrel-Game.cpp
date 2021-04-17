// Squirrel-Engine.cpp : Defines the entry point for the application.
//

#include "../Squirrel-Engine/include/Squirrel.h"
#include "include/Skeleton.h"
#include "include/Camera.h"
#include "include/Light.h"
#include "Squirrel-Game.h"


class Sandbox : public Application
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

Application* CreateApplication()
{
	return new Sandbox();
}

void Sandbox::Run()
{

  TestControlSchema* testSchema = new TestControlSchema();
	Squirrel::InterfaceFactory::getInstance().getIPInterface().setControlSchema(testSchema);
	Camera* mainCamera = new Camera();
	InterfaceFactory::getInstance().getGMInterface().levelStore->spawnNewActor(EActorType::CAMERA, mainCamera);
	//
	Skeleton* skeleton = new Skeleton();
	skeleton->health = 100;
	skeleton->attackPower = 50;
	skeleton->transformComponent->setTransform(0, 0, -60);
	skeleton->transformComponent->setRotation(20, 20, 20);
	InterfaceFactory::getInstance().getGMInterface().levelStore->spawnNewActor(EActorType::ACTOR, skeleton);
	//
	Skeleton* skeleton1 = new Skeleton();
	skeleton1->health = 100;
	skeleton1->attackPower = 50;
	skeleton1->transformComponent->setTransform(0, 10, -50);
	skeleton1->transformComponent->setRotation(-20, -20, -20);
	InterfaceFactory::getInstance().getGMInterface().levelStore->spawnNewActor(EActorType::ACTOR, skeleton1);
	//
	Light* light = new Light();
	light->transformComponent->setTransform(0, 20, -20);
	light->lightComponent->setColor(1, 0, 0);
	InterfaceFactory::getInstance().getGMInterface().levelStore->spawnNewActor(EActorType::LIGHT, light);

}
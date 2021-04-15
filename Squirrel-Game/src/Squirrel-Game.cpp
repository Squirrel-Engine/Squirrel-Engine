// Squirrel-Engine.cpp : Defines the entry point for the application.
//

#include "../Squirrel-Engine/include/Squirrel.h"
#include "../../Squirrel-Engine/include/Mesh.h"
#include "Components/RenderComponent.h"
#include "Components/CameraComponent.h"
#include "include/Skeleton.h"
#include "include/Camera.h"
#include "include/Light.h"

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
	Camera* mainCamera = new Camera();
	Squirrel::InterfaceFactory::getInstance().getGMInterface().levelStore->spawnNewActor(Squirrel::EActorType::CAMERA, mainCamera);
	//
	Skeleton* skeleton = new Skeleton();
	skeleton->transformComponent->setTransform(0, 0, -30);
	skeleton->transformComponent->setRotation(20, 20, 20);
	Squirrel::InterfaceFactory::getInstance().getGMInterface().levelStore->spawnNewActor(Squirrel::EActorType::ACTOR, skeleton);
	//
	Skeleton* skeleton1 = new Skeleton();
	skeleton1->health = 100;
	skeleton1->attackPower = 50;
	skeleton1->transformComponent->setTransform(0, 10, -50);
	skeleton1->transformComponent->setRotation(-20, -20, -20);
	Squirrel::InterfaceFactory::getInstance().getGMInterface().levelStore->spawnNewActor(Squirrel::EActorType::ACTOR, skeleton1);
	//
	Light* light = new Light();
	light->transformComponent->setTransform(0, 0, 50);
	light->lightComponent->setColor(1, 0, 0);
	Squirrel::InterfaceFactory::getInstance().getGMInterface().levelStore->spawnNewActor(Squirrel::EActorType::LIGHT, light);
}
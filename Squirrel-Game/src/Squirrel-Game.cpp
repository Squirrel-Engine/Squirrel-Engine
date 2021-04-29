// Squirrel-Engine.cpp : Defines the entry point for the application.
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

	~Sandbox() override
	{
	}

	void Run() override;
};

Application* CreateApplication()
{
	return new Sandbox();
}

void Sandbox::Run()
{
	auto testSchema = new TestControlSchema();
	getInterface<IP_Interface>().setControlSchema(testSchema);
	//
	auto mainCamera = new Camera();
	getInterface<GM_Interface>().levelStore->spawnNewActor(EActorType::CAMERA, mainCamera);
	//
	auto skeleton = new Skeleton();
	skeleton->health = 100;
	skeleton->attackPower = 50;
	skeleton->transformComponent->setTransform(0, 3, -5);
	skeleton->transformComponent->setScale(0.05, 0.05, 0.05);
	skeleton->renderComponent->C_ShaderID = 0;
	skeleton->renderComponent->C_ModelID = 3;
	skeleton->renderComponent->C_MaterialID_0 = 2;

	skeleton->audioComponent->C_AudioSourceID = 0;
	getInterface<GM_Interface>().levelStore->spawnNewActor(EActorType::ACTOR, skeleton);
	//
	auto light = new Light();
	light->transformComponent->setTransform(0, 0, +10);
	getInterface<GM_Interface>().levelStore->spawnNewActor(EActorType::LIGHT, light);
}
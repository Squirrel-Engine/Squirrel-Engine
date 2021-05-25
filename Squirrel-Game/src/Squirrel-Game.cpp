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
	auto mainCamera = LevelStore::createActor<Camera>(EActorType::CAMERA, "MainCamera");
	//
	for (int i = 0; i < 1; i++) {
		auto skeleton = LevelStore::createActor<Skeleton>(EActorType::ACTOR, "skeleton"+i);
		skeleton->health = 100;
		skeleton->attackPower = 50;
		skeleton->transformComponent.setTransform(0, 3, -5);
		skeleton->transformComponent.setScale(0.05, 0.05, 0.05);
		skeleton->renderComponent.C_ShaderID = 0;
		skeleton->renderComponent.C_ModelID = 3;
		skeleton->audioComponent.C_AudioSourceID = 0;
	}
	//
	auto light = LevelStore::createActor<Light>(EActorType::LIGHT, "firstLight");

	light->transformComponent.setTransform(0, 0, 10);


	

}
// Squirrel-Engine.cpp : Defines the entry point for the application.
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
	//Set custom control schema
	auto testSchema = new TestControlSchema();
	getInterface<IP_Interface>().setControlSchema(testSchema);
	
	//Create a actor via Camera class to make it a First Person Player
	auto Player = LevelStore::createActor<Camera>(EActorType::CAMERA, "Player");
	Player->lightComponent.setLightType(ELightType::SpotLight);

	//Create a game object and set its transformation
	auto Statue = LevelStore::createActor<Skeleton>(EActorType::ACTOR, "Statue");
	Statue->transformComponent.setTransform(18, -3, 17);
	Statue->transformComponent.setScale(0.03, 0.03, 0.03);
	Statue->renderComponent.C_ShaderID = 0;		//Shader
	Statue->renderComponent.C_ModelID = 2;		//Model
	Statue->audioComponent.C_AudioSourceID = 0;	//Audio Source

	auto Map = LevelStore::createActor<Skeleton>(EActorType::ACTOR, "Map");
	Map->transformComponent.setTransform(0, -5, 0);
	Map->transformComponent.setScale(0.05, 0.05, 0.05);
	Map->renderComponent.C_ShaderID = 0;
	Map->renderComponent.C_ModelID = 3;
	Map->audioComponent.C_AudioSourceID = 0;

	//Add light sources to the scene
	auto FirstLight = LevelStore::createActor<Light>(EActorType::LIGHT, "FirstLight");
	FirstLight->transformComponent.setTransform(0, 5, 35);

	auto SecondLight = LevelStore::createActor<Light>(EActorType::LIGHT, "SecondLight");
	SecondLight->transformComponent.setTransform(0, 5, 0);
}
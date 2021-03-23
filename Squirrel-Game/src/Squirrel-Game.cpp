// Squirrel-Engine.cpp : Defines the entry point for the application.
//
#include "Skeleton.h"
#include "../Squirrel-Engine/include/Squirrel.h"
#include "../../Squirrel-Engine/include/Mesh.h"
#include "Components/RenderComponent.h"
#include "Components/AudioComponent.h"
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
	skeleton->transformComponent->setTransform(glm::vec3(0, -0.5f, -10.0f));
	skeleton->transformComponent->setRotation(glm::vec3(0.0f, -5.0f, 0.0f));
	skeleton->insertComponent("transformComponent", transformComponent);


	
	RenderComponent* renderComponent = new RenderComponent();
	
	renderComponent->C_ModelID = 0;
	renderComponent->C_MaterialID_0 = 1;
	renderComponent->C_MaterialID_1 = 1;
	renderComponent->C_ShaderID = 0;
	renderComponent->setup();
	
	renderComponent->setParent(skeleton);
	skeleton->renderComponent = renderComponent;
	skeleton->insertComponent("renderComponent", renderComponent);
	

	AudioComponent* audioComponent = new AudioComponent();

	audioComponent->C_AudioSourceID = 0;
	audioComponent->setup();
	audioComponent->setParent(skeleton);
	skeleton->audioComponent = audioComponent;
	skeleton->insertComponent("audioComponent", audioComponent);
	audioComponent->play();



	Squirrel::InterfaceFactory::getInstance().getGMInterface().levelStore->spawnNewActor(skeleton);


	//Squirrel::InterfaceFactory::getInstance().getAUInterface().playAudio(Squirrel::InterfaceFactory::getInstance().getRMInterface().getAudio(2)->audioObject);

	

}
// Squirrel-Engine.cpp : Defines the entry point for the application.
//
#include "../Squirrel-Engine/include/Squirrel.h"
#include "../../Squirrel-Engine/include/Mesh.h"

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
	//DrawCall(Model, Shader, Texture)
	DrawCall* drawCall = new DrawCall("../../Squirrel-Engine/res/models/backpack/backpack.obj",
									  "../../Squirrel-Engine/res/shaders/Model.shader",
									  "../../Squirrel-Engine/res/textures/wall.jpg");
	

	Squirrel::InterfaceFactory::getInstance()->getRDInterface()->submitDrawCall(drawCall);
}


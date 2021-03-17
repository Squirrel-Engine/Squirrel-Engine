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
	//DrawCall(Model, Shader)
	Shader *shader = new Shader("../../Squirrel-Engine/res/shaders/Model.shader");
	Model *model3D = new Model("../../Squirrel-Engine/res/models/Model1.obj");

	DrawCall* drawCall = new DrawCall( *model3D, *shader );
	
	Squirrel::InterfaceFactory::getInstance().getRDInterface().submitDrawCall(drawCall);

}
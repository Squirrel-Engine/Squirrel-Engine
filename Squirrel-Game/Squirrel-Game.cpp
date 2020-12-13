// Squirrel-Engine.cpp : Defines the entry point for the application.
//
#include "../Squirrel-Engine/include/Squirrel.h"
#include "../Squirrel-Engine/include/RD_Interface.h"
class Sandbox : public Squirrel::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Squirrel::Application* Squirrel::CreateApplication()
{
	float firstTriangle[] = {
		//positions          //colors                                       
		-0.9f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // left 
		-0.0f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // right
		-0.45f, 0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  // top 
	};
	
	return new Sandbox();
}
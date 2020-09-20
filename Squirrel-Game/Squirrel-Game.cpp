// Squirrel-Engine.cpp : Defines the entry point for the application.
//

#include "../Squirrel-Engine/include/Squirrel.h"

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
	return new Sandbox();
}
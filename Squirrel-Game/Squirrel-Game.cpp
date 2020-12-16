// Squirrel-Engine.cpp : Defines the entry point for the application.
//
#include "../Squirrel-Engine/include/Squirrel.h"
#include "../Squirrel-Engine/include/ED_Interface.h"
#include "../Squirrel-Engine/include/StoreManager.h"
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
	std::cout << Squirrel::Engine::GetRenderEngineName() << std::endl;
	std::cout << Squirrel::StoreManager::getInstance()->getLevelStore()->x<< std::endl;
	return new Sandbox();
}
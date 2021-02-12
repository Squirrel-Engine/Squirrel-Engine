#pragma once
#include <iostream>
#include "Application.h"
#include "MT_Interface.h"
#include "RD_Interface.h"
#include "RuntimeManager.h"
#include "DrawCall.h"
#include "InterfaceFactory.h"

extern Squirrel::Application* Squirrel::CreateApplication();

int main(int argc, char** argv)
{
    Squirrel::RuntimeManager* runtimeManager = Squirrel::RuntimeManager::getInstance();
	
	
	//RD_Interface 
	auto app = Squirrel::CreateApplication();
	
	
	runtimeManager->engineStartup();

	app->Run();
	
    Squirrel::InterfaceFactory::getInstance()->getMTInterface()->startScheduler();
	runtimeManager->engineShutdown();
	
	delete app;
}
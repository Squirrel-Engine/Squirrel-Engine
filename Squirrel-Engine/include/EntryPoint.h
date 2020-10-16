#pragma once
#include <iostream>

#include "Application.h"
#include "MT_Interface.h"
#include "RuntimeManager.h"

extern Squirrel::Application* Squirrel::CreateApplication();

int main(int argc, char** argv)
{
    Squirrel::RuntimeManager* r = Squirrel::RuntimeManager::getInstance();
    Squirrel::MT_Interface* mt_Interface = new Squirrel::MT_Interface();
	auto app = Squirrel::CreateApplication();
	
    r->engineStartup();
	
	app->Run();
	
	mt_Interface->startScheduler();
	
    r->engineShutdown();
	
	delete app;
}
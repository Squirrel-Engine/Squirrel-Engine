#pragma once
#include <iostream>

#include "Application.h"
#include "RuntimeManager.h"

extern Squirrel::Application* Squirrel::CreateApplication();

int main(int argc, char** argv)
{
    Squirrel::RuntimeManager* r = Squirrel::RuntimeManager::getInstance();
	auto app = Squirrel::CreateApplication();
    r->engineStartup();
	app->Run();
    r->engineShutdown();
	delete app;
}
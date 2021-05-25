#pragma once
#include <iostream>
#include "Application.h"
#include "RuntimeManager.h"
#include "InterfaceFactory.h"
#include "Timer.h"

int main(int argc, char** argv)
{
	RuntimeManager runtimeManager = RuntimeManager::getInstance();

	auto app = CreateApplication();

	runtimeManager.engineStartup();
	app->Run();
	getInterface<GM_Interface>().configureComponents();
	getInterface<MT_Interface>().startScheduler();
	runtimeManager.engineShutdown();
	
	delete app;
}
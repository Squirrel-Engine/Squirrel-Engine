#pragma once
#include <iostream>
#include "Application.h"
#include "MT_Interface.h"
#include "RD_Interface.h"
#include "RuntimeManager.h"
#include "DrawCall.h"
#include "InterfaceFactory.h"

int main(int argc, char** argv)
{
    RuntimeManager runtimeManager = RuntimeManager::getInstance();
	
	
	//RD_Interface 
	auto app = CreateApplication();
	
	runtimeManager.engineStartup();
	app->Run();

	InterfaceFactory::getInstance().getMTInterface().startScheduler();
	runtimeManager.engineShutdown();

	delete app;
}
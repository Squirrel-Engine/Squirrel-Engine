#pragma once
#include <iostream>
#include "Application.h"
#include "MT_Interface.h"
#include "RD_Interface.h"
#include "RuntimeManager.h"
#include "DrawCall.h"
#include "InterfaceFactory.h"
#include "AL/al.h"
#include "AL/alc.h"
#include <bit>
int main(int argc, char** argv)
{
	RuntimeManager runtimeManager = RuntimeManager::getInstance();


	//RD_Interface 
	auto app = CreateApplication();

	runtimeManager.engineStartup();
	app->Run();

	getInterface<MT_Interface>().startScheduler();
	runtimeManager.engineShutdown();

	delete app;
}

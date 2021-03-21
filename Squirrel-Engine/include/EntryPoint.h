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
    Squirrel::RuntimeManager runtimeManager = Squirrel::RuntimeManager::getInstance();
	

	auto app = Squirrel::CreateApplication();

	runtimeManager.engineStartup();
	app->Run();

	Squirrel::InterfaceFactory::getInstance().getMTInterface().startScheduler();
	runtimeManager.engineShutdown();

	delete app;
}


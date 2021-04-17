#pragma once
#include "Core.h"

class Application
{
public:
	Application();
	virtual ~Application();

	virtual void Run() = 0;
};

// To be defined in CLIENT
Application* CreateApplication();

#pragma once
#include "Core.h"
#include "DummyScheduler.h"
#include "Jobs.h"

namespace Squirrel {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();
		virtual void ConfigureMap();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

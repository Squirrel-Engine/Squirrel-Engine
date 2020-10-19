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

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

#include "include/Application.h"
#include "include/RenderConfig.h"
#include "include/Scheduler.h"
#include "include/MockStateManager.h"

namespace Squirrel {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		MockStateManager::getInstance()->JobQueue.push(new J_Window_CreateWindow());
		Scheduler scheduler;
		scheduler.Start();
	}
}

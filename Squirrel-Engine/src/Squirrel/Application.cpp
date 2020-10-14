#include "include/Application.h"

namespace Squirrel {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		lowPriJobQueue.push(new J_Window_CreateWindow());
		Scheduler scheduler;
		scheduler.start();
	}
}

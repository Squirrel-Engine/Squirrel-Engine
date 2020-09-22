#include "../../include/Application.h"
#include <iostream>
#include "../../include/WindowManager.h"
#include <GLFW/glfw3.h>

namespace Squirrel {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

    void Application::Run()
    {
		WindowManager windowManager = WindowManager(800,600,"Engine");
		windowManager.createWindow();
		windowManager.renderWindow();

    }
}

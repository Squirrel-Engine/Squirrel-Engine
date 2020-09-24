#include "../../include/Application.h"
#include <iostream>

#include "../../include/Vector2.h"
#include "../../include/WindowManager.h"

namespace Squirrel {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

    void Application::Run()
    {
		WindowManager windowManager = WindowManager(800,600,"TEST");
		windowManager.createWindow();
		windowManager.renderWindow();
    }
}

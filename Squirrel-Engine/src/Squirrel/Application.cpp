#include "../../include/Application.h"
#include <iostream>
#include "../../include/JSONConfigurator.h"
#include "../../include/Vector2.h"
#include "../../include/WindowManager.h"
#include "../../include/RenderConfig.h"
namespace Squirrel {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

    void Application::Run()
    {
		RenderConfig r;
		r.setup();
    }
}

#pragma once
#include "GLFW/glfw3.h"

#include "RD_Interface.h"
#include "InterfaceFactory.h"
namespace Squirrel
{
	namespace Rendering
	{
		GLFWwindow* GetRenderingWindow();
		int GetCurrentFPS();
	}


}

#pragma once
#include <GLFW/glfw3.h>
#include "EGraphicAPI.h"
namespace Squirrel {

	class Window
	{
	public:
		GLFWwindow* getGLWindow();
		void setGLWindow(GLFWwindow* window);

	private:
		GLFWwindow* glWindow;
		Squirrel::EGraphicAPI getCurrentPlatform();
	};
	
} 

#pragma once
#include "Window.h"
#include "OpenGLWR.h"
#include "EGraphicAPI.h"
#include "Configuration.h"
#include "Store.h"
namespace Squirrel
{
	class WindowManager
	{
	public:
		void createWindow();
		void closeWindow();
		void renderWindow();
		void renderWindow(Window window);
		EGraphicAPI getCurrentPlatform();
		Window getWindow();
		WindowManager(int screenWidth, int screenHeight, std::string windowName);
		WindowManager();
	private:
		OpenGLWR openglWR;
		int screenWidth;
		int screenHeight;
		std::string windowName;
	};

}



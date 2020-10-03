#pragma once
#include "../../../include/Window.h"
#include "../../../include/OpenGLWR.h"
#include "../../../include/EGraphicAPI.h"

namespace Squirrel
{
	class WindowManager
	{
	public:
		void createWindow();
		void closeWindow();
		void renderWindow();
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



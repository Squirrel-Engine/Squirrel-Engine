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
		Squirrel::EGraphicAPI getCurrentPlatform();
		Squirrel::Window getWindow();
		WindowManager(int screenWidth, int screenHeight, std::string windowName);

	private:
		OpenGLWR openglWR;
		int screenWidth;
		int screenHeight;
		std::string windowName;
	};

}



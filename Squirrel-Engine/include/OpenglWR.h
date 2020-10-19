#pragma once
#include<iostream>
#include "IWindowRenderer.h"
#include "Window.h"
namespace Squirrel
{
	class OpenGLWR :Squirrel::IWindowRenderer
	{
	public:
		void startUp(int screenWidth, int screenHeight, std::string windowName);
		void shutDown();
		Squirrel::Window getWindow();
		void render();
	private:
		Squirrel::Window window;
	};

}

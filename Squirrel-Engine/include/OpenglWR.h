#pragma once
#include<iostream>
#include "../../../include/IWindowRenderer.h"
#include "../../../include/Window.h"

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

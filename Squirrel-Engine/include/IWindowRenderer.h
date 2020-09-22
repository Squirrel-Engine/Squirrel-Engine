#pragma once
#include "Window.h"

namespace Squirrel {
	class IWindowRenderer
	{
	public:
		virtual void startUp(int screenWidth, int screenHeight, std::string windowName) = 0;
		virtual void shutDown() = 0;
		virtual Window getWindow() = 0;
		virtual void render() = 0;
	};
}



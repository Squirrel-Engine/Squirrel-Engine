#pragma once
#include <string>

#include "Window.h"

namespace Squirrel
{
	static struct RenderStore
	{
		int SCREEN_WIDTH;
		int SCREEN_HEIGHT;
		std::string WINDOW_NAME;
		Window WINDOW;
	} renderStore;

}

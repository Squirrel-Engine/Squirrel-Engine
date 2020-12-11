#pragma once
#include "Window.h"

namespace Squirrel
{
	class Fur
	{
	public:
		Fur();
		void startRenderEngine();
		void pauseRenderEngine();
		void stopRenderEngine();

		void render();
		void addActorToRenderQueue();

		void updateRenderEngineOptions();

		//TODO: Return type should be Window
		void glfwWindow();

	};


}

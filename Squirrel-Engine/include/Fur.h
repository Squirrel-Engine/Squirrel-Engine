#pragma once
#include <iostream>
#include "Window.h"
#include "RenderOptions.h"
#include "Utilities.h"
#include "Renderer.h"

namespace Fur
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

		void updateRenderEngineOptions(std::string parameterName, int parameter);
		void updateRenderEngineOptions(std::string parameterName, float parameter);
		void updateRenderEngineOptions(std::string parameterName, std::string parameter);

		//TODO: Return type should be Window

		GLFWwindow* getGlfwWindow();
	};
}

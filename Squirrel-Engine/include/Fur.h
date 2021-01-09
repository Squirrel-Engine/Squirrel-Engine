#pragma once
#include <iostream>
#include <string.h>
#include "Window.h"
#include "Renderer.h"
#include "Configuration.h"

namespace Fur
{
	class Fur
	{
	public:
		Fur();
		void startRenderEngine();
		void pauseRenderEngine();
		void stopRenderEngine();

		void render(RenderObject& data);
		void addActorToRenderQueue(RenderObject& data);

		void updateRenderEngineOptions(std::string parameterName, int parameter);
		void updateRenderEngineOptions(std::string parameterName, float parameter);
		void updateRenderEngineOptions(std::string parameterName, std::string parameter);

		//TODO: Return type should be Window

		GLFWwindow* getGlfwWindow();
	};
}

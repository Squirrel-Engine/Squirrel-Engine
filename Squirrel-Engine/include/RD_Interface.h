#pragma once
#include "Window.h"
#include "Fur.h"
#include "Configuration.h"
#include <iostream>
#include <string.h>


namespace Squirrel
{
	class RD_Interface
	{
	public:
		RD_Interface();
		void startRenderEngine();
		void pauseRenderEngine();
		void stopRenderEngine();

		void render();
		void addActorToRenderQueue(const void* data);

		//TODO: Refactoring Point
		void updateRenderEngineOptions(std::string parameterName, int parameter);
		void updateRenderEngineOptions(std::string parameterName, float parameter);
		void updateRenderEngineOptions(std::string parameterName, std::string parameter);
		
		//OpenGL Specific
		//TODO: Return type should be Window
		GLFWwindow* getGlfwWindow();

	private:
		Fur::Fur* fur;
	};


}
#pragma once
#include "Window.h"
#include "Fur.h"
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
		void addActorToRenderQueue();

		void updateRenderEngineOptions();
		
		//OpenGL Specific
		//TODO: Return type should be Window
		void glfwWindow();

	private:
		Fur* fur;
	};


}

#include "include/Fur.h"

namespace Fur
{	
	Fur::Fur()
	{

	}
	
	void Fur::startRenderEngine()
	{
		renderOptions->screenHeight = 600;
		renderOptions->screenWidth = 800;
		renderOptions->windowName = "Fur Renderer";
	}

	void Fur::pauseRenderEngine()
	{
		
	}

	void Fur::stopRenderEngine()
	{
		
	}

	void Fur::render()
	{
		std::cout << "Fur is Running" << std::endl;
	}

	void Fur::addActorToRenderQueue()
	{
		
	}

	void Fur::glfwWindow()
	{
		
	}

	void Fur::updateRenderEngineOptions(std::string parameterName, int parameter)
	{
		
	}

	void Fur::updateRenderEngineOptions(std::string parameterName, float parameter)
	{
		
	}

	void Fur::updateRenderEngineOptions(std::string parameterName, std::string parameter)
	{
		
	}
}
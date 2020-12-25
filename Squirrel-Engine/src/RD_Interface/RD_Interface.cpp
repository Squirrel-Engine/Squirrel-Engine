#include "include/RD_Interface.h"

namespace Squirrel
{
	RD_Interface::RD_Interface()
	{
		fur = new Fur::Fur();
	}

	void RD_Interface::startRenderEngine()
	{
		try
		{
			switch (Configuration::getInstance()->renderConfig.renderer)
			{
			case ERenderer::Fur:
				fur->startRenderEngine();
				
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}

	void RD_Interface::pauseRenderEngine()
	{
		try
		{
			switch (Configuration::getInstance()->renderConfig.renderer)
			{
			case ERenderer::Fur:
				fur->pauseRenderEngine();

			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}

	void RD_Interface::stopRenderEngine()
	{
		try
		{
			switch (Configuration::getInstance()->renderConfig.renderer)
			{
			case ERenderer::Fur:
				fur->stopRenderEngine();

			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}

	void RD_Interface::render()
	{
		try
		{
			switch (Configuration::getInstance()->renderConfig.renderer)
			{
			case ERenderer::Fur:
				fur->render();

			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}

	void RD_Interface::addActorToRenderQueue(const void* data)
	{
		try
		{
			switch (Configuration::getInstance()->renderConfig.renderer)
			{
			case ERenderer::Fur:
				fur->addActorToRenderQueue(data);

			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}

	GLFWwindow* RD_Interface::getGlfwWindow()
	{
		try
		{
			switch (Configuration::getInstance()->renderConfig.renderer)
			{
			case ERenderer::Fur:
				return fur->getGlfwWindow();

			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}

	void RD_Interface::updateRenderEngineOptions(std::string parameterName, int parameter)
	{
		try
		{
			switch (Configuration::getInstance()->renderConfig.renderer)
			{
			case ERenderer::Fur:
				fur->updateRenderEngineOptions(parameterName, parameter);

			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}

	void RD_Interface::updateRenderEngineOptions(std::string parameterName, float parameter)
	{
		try
		{
			switch (Configuration::getInstance()->renderConfig.renderer)
			{
			case ERenderer::Fur:
				fur->updateRenderEngineOptions(parameterName, parameter);

			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}

	void RD_Interface::updateRenderEngineOptions(std::string parameterName, std::string parameter)
	{
		try
		{
			switch (Configuration::getInstance()->renderConfig.renderer)
			{
			case ERenderer::Fur:
				fur->updateRenderEngineOptions(parameterName, parameter);

			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	


	
}

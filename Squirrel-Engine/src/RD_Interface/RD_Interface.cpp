#include "include/RD_Interface.h"
#include "include/Configuration.h"
#include <iostream>

namespace Squirrel
{
	RD_Interface::RD_Interface()
	{
		fur = new Fur();
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

	void RD_Interface::addActorToRenderQueue()
	{
		try
		{
			switch (Configuration::getInstance()->renderConfig.renderer)
			{
			case ERenderer::Fur:
				fur->addActorToRenderQueue();

			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}

	void RD_Interface::glfwWindow()
	{
		try
		{
			switch (Configuration::getInstance()->renderConfig.renderer)
			{
			case ERenderer::Fur:
				fur->glfwWindow();

			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}

	void RD_Interface::updateRenderEngineOptions()
	{
		try
		{
			switch (Configuration::getInstance()->renderConfig.renderer)
			{
			case ERenderer::Fur:
				fur->updateRenderEngineOptions();

			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	


	
}


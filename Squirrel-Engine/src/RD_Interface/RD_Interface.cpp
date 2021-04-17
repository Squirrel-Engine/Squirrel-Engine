#include "RD_Interface.h"

void RD_Interface::startRenderEngine()
{
	try
	{
		switch (Configuration::getInstance().renderConfig.renderer)
		{
		case ERenderer::Fur:
			fur.startRenderEngine();
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
		switch (Configuration::getInstance().renderConfig.renderer)
		{
		case ERenderer::Fur:
			fur.pauseRenderEngine();
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
		switch (Configuration::getInstance().renderConfig.renderer)
		{
		case ERenderer::Fur:
			fur.stopRenderEngine();
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
		switch (Configuration::getInstance().renderConfig.renderer)
		{
		case ERenderer::Fur:
			fur.render();
			break;
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
		switch (Configuration::getInstance().renderConfig.renderer)
		{
		case ERenderer::Fur:
			fur.addActorToRenderQueue();
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void RD_Interface::submitDrawCall(DrawCall& drawCall)
{
	try
	{
		switch (Configuration::getInstance().renderConfig.renderer)
		{
		case ERenderer::Fur:
			fur.submitDrawCall(drawCall);
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
		switch (Configuration::getInstance().renderConfig.renderer)
		{
		case ERenderer::Fur:
			fur.updateRenderEngineOptions(parameterName, parameter);
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
		switch (Configuration::getInstance().renderConfig.renderer)
		{
		case ERenderer::Fur:
			fur.updateRenderEngineOptions(parameterName, parameter);
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
		switch (Configuration::getInstance().renderConfig.renderer)
		{
		case ERenderer::Fur:
			fur.updateRenderEngineOptions(parameterName, parameter);
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

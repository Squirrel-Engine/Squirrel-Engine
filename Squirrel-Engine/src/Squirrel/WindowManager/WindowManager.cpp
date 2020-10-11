#include "include/WindowManager.h"
#include "include/Configuration.h"


namespace Squirrel
{
	void WindowManager::createWindow() {
		switch (getCurrentPlatform())
		{
		case EGraphicAPI::OPENGL:
			openglWR.startUp(screenWidth, screenHeight, windowName);
			break;
		case EGraphicAPI::DIRECTX:
			break;
		case EGraphicAPI::VULKAN:
			break;
		default:
			break;
		}
	}

	void WindowManager::closeWindow() {
		switch (getCurrentPlatform())
		{
		case EGraphicAPI::OPENGL:
			openglWR.shutDown();
			break;
		case EGraphicAPI::DIRECTX:
			break;
		case EGraphicAPI::VULKAN:
			break;
		default:
			break;
		}
	}

	void WindowManager::renderWindow() {
		switch (getCurrentPlatform())
		{
		case EGraphicAPI::OPENGL:
			openglWR.render();
			break;
		case EGraphicAPI::DIRECTX:
			break;
		case EGraphicAPI::VULKAN:
			break;
		default:
			break;
		}
	}

	EGraphicAPI WindowManager::getCurrentPlatform() {
		return Configuration::getInstance()->renderConfig.graphicAPI;
	}

	Window WindowManager::getWindow() {
		switch (getCurrentPlatform())
		{
		case EGraphicAPI::OPENGL:
			return openglWR.getWindow();
			break;
		case EGraphicAPI::DIRECTX:
			break;
		case EGraphicAPI::VULKAN:
			break;
		default:
			break;
		}
	}

	WindowManager::WindowManager(int _screenWidth, int _screenHeight, std::string _windowName) {
		this->screenWidth = _screenWidth;
		this->screenHeight = _screenHeight;
		this->windowName = _windowName;
	}

	WindowManager::WindowManager() {
		this->screenWidth = Configuration::getInstance()->renderConfig.screenWidth;
		this->screenHeight = Configuration::getInstance()->renderConfig.screenHeight;
		this->windowName = Configuration::getInstance()->renderConfig.windowName;
	}
}

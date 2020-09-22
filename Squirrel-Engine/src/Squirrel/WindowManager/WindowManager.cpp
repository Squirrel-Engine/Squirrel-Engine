#include "../../../include/WindowManager.h"
void WindowManager::createWindow() {
	switch (getCurrentPlatform())
	{
	case Squirrel::EPlatform::OPENGL:
		openglWR.startUp(screenWidth, screenHeight, windowName);
		break;
	case Squirrel::EPlatform::DIRECTX:
		break;
	case Squirrel::EPlatform::VULKAN:
		break;
	default:
		break;
	}
}

void WindowManager::closeWindow() {
	switch (getCurrentPlatform())
	{
	case Squirrel::EPlatform::OPENGL:
		openglWR.shutDown();
		break;
	case Squirrel::EPlatform::DIRECTX:
		break;
	case Squirrel::EPlatform::VULKAN:
		break;
	default:
		break;
	}
}

void WindowManager::renderWindow() {
	switch (getCurrentPlatform())
	{
	case Squirrel::EPlatform::OPENGL:
		openglWR.render();
		break;
	case Squirrel::EPlatform::DIRECTX:
		break;
	case Squirrel::EPlatform::VULKAN:
		break;
	default:
		break;
	}
}

Squirrel::EPlatform WindowManager::getCurrentPlatform() {
	return Squirrel::EPlatform::OPENGL;
}

Squirrel::Window WindowManager::getWindow() {
	switch (getCurrentPlatform())
	{
	case Squirrel::EPlatform::OPENGL:
		return openglWR.getWindow();
		break;
	case Squirrel::EPlatform::DIRECTX:
		break;
	case Squirrel::EPlatform::VULKAN:
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
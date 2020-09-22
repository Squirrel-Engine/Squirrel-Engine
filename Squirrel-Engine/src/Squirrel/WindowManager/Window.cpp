#include "../../../include/Window.h"

GLFWwindow* Squirrel::Window::getGLWindow() {
	return glWindow;
}

Squirrel::EPlatform Squirrel::Window::getCurrentPlatform() {
	return EPlatform::OPENGL;
	//TODO: Implement central platform data distribution
}

void Squirrel::Window::setGLWindow(GLFWwindow* window) {
	glWindow = window;
}
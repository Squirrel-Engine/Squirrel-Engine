#include "../../../include/Window.h"

namespace Squirrel
{
	GLFWwindow* Window::getGLWindow() {
		return glWindow;
	}

	EGraphicAPI Window::getCurrentPlatform() {
		return EGraphicAPI::OPENGL;
		//TODO: Implement central platform data distribution
	}

	void Window::setGLWindow(GLFWwindow* window) {
		glWindow = window;
	}
}

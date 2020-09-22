#include "../../../include/Window.h"

namespace Squirrel
{
	GLFWwindow* Window::getGLWindow() {
		return glWindow;
	}

	Squirrel::EPlatform Window::getCurrentPlatform() {
		return EPlatform::OPENGL;
		//TODO: Implement central platform data distribution
	}

	void Window::setGLWindow(GLFWwindow* window) {
		glWindow = window;
	}
}

#include "include/Window.h"

namespace Squirrel
{
	GLFWwindow* Window::getGLWindow() {
		return glWindow;
	}


	void Window::setGLWindow(GLFWwindow* window) {
		glWindow = window;
	}
}

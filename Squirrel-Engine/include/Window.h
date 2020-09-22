#include <GLFW/glfw3.h>
#include "../../../include/EPlatform.h"
namespace Squirrel {
	class Window
	{
	public:
		GLFWwindow* getGLWindow();
		void setGLWindow(GLFWwindow* window);

	private:
		GLFWwindow* glWindow;
		Squirrel::EPlatform getCurrentPlatform();
	};
}

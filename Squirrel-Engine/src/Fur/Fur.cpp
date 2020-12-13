#include "include/Fur.h"
#include "include/FurStore.h"
namespace Fur
{	
	Fur::Fur()
	{

	}

	void Fur::startRenderEngine()
	{
		renderOptions->screenHeight = 600;
		renderOptions->screenWidth = 800;
		renderOptions->windowName = "Fur Renderer";

		//START
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
		furWindow =  glfwCreateWindow(renderOptions->screenWidth, renderOptions->screenHeight, "Fur Renderer", NULL, NULL);
		if (furWindow == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}
		glfwMakeContextCurrent(furWindow);

		// glad: load all OpenGL function pointers
		// ---------------------------------------
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			glfwTerminate();
		}
	}

	void Fur::pauseRenderEngine()
	{
		
	}

	void Fur::stopRenderEngine()
	{
		
	}

	void Fur::render()
	{
		furRender();
	}

	void Fur::addActorToRenderQueue()
	{
		
	}

	GLFWwindow* Fur::getGlfwWindow()
	{
		return furWindow;
	}

	void Fur::updateRenderEngineOptions(std::string parameterName, int parameter)
	{
		
	}

	void Fur::updateRenderEngineOptions(std::string parameterName, float parameter)
	{
		
	}

	void Fur::updateRenderEngineOptions(std::string parameterName, std::string parameter)
	{
		
	}

}
#include "include/Fur.h"

namespace Fur
{	
	Fur::Fur()
	{

	}

	void Fur::startRenderEngine()
	{
		//access all rendering options
		Squirrel::RenderConfig config = Squirrel::Configuration::getInstance()->renderConfig;
		
		//start
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		
		furWindow =  glfwCreateWindow(config.screenWidth, config.screenHeight, config.windowName.c_str(), NULL, NULL);
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
		glViewport(0, 0, config.screenWidth, config.screenHeight);
		
		glBindVertexArray(0);
	}

	void Fur::pauseRenderEngine()
	{
		
	}

	void Fur::stopRenderEngine()
	{
		
	}

	void Fur::render(RenderObject& data)
	{
		furRender(data);
	}

	void Fur::addActorToRenderQueue(RenderObject& data)
	{
		render(data);
	}

	void Fur::submitDrawCall()
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

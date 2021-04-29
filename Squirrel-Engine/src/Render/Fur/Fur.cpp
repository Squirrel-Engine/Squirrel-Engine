#include "Fur.h"
void error_callback(int error, const char* msg);

Fur::Fur()
{

}

void Fur::startRenderEngine()
{
	glfwSetErrorCallback(error_callback);
	//access all rendering options
	RenderConfig config = Configuration::getInstance().renderConfig;
	
	//start
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 4);

	furWindow = glfwCreateWindow(config.screenWidth, config.screenHeight, config.windowName.c_str(), nullptr, nullptr);
	if (furWindow == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(furWindow);
	glfwSetFramebufferSizeCallback(furWindow, framebuffer_size_callback);
	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
	}
	glViewport(0, 0, config.screenWidth, config.screenHeight);

	glBindVertexArray(0);
	//
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glEnable(GL_MULTISAMPLE);
	glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
}

void Fur::pauseRenderEngine()
{
}

void Fur::stopRenderEngine()
{
}

void Fur::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

void Fur::render()
{
	furRender();
}

void Fur::addActorToRenderQueue()
{
	render();
}

void Fur::submitDrawCall(DrawCall& drawCall)
{
	firstCommandBuffer->push(&drawCall);
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

void error_callback(int error, const char* msg){
	std::string s;
	s = " [" + std::to_string(error) + "] " + msg + '\n';
	std::cerr << s << std::endl;
}
#pragma once
#include "Renderer.h"
#include "Configuration.h"

class Fur
{
public:
	Fur();
	void startRenderEngine();
	void pauseRenderEngine();
	void stopRenderEngine();
	void static framebuffer_size_callback(GLFWwindow* window, int width, int height);

	void render();
	void addActorToRenderQueue();
	void submitDrawCall(DrawCall& drawCall);

	void updateRenderEngineOptions(std::string parameterName, int parameter);
	void updateRenderEngineOptions(std::string parameterName, float parameter);
	void updateRenderEngineOptions(std::string parameterName, std::string parameter);

	//TODO: Return type should be Window

	GLFWwindow* getGlfwWindow();
};


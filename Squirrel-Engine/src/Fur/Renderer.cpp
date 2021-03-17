#include "Renderer.h"

void furRender()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	for (auto& drawcall : *firstCommandBuffer) {
		drawcall->model.Draw(drawcall->shader);
	}

	glfwSwapBuffers(furWindow);
	glfwPollEvents();
}
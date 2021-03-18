#include "Renderer.h"

#include <queue>

void furRender()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	for (int i = 0; i < firstCommandBuffer->size(); i++) {
		DrawCall* drawcall = firstCommandBuffer->front();
		if(drawcall != nullptr)
		{
			drawcall->model->Draw(*drawcall->shader);
			firstCommandBuffer->pop();
			delete drawcall;
		}
	}
	
	glfwSwapBuffers(furWindow);
	glfwPollEvents();
}

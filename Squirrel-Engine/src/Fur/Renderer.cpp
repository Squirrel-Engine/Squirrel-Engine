#include "Renderer.h"
#include <queue>

void furRender()
{
	DrawCall* drawcall;
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < firstCommandBuffer->size(); i++) {
		if (firstCommandBuffer->front() != nullptr) {
			drawcall = firstCommandBuffer->front();
			drawcall->model->Draw(*drawcall->shader, drawcall->uniformDesc);
			firstCommandBuffer->pop();
			
		}

	}

	glfwSwapBuffers(furWindow);
	glfwPollEvents();
}

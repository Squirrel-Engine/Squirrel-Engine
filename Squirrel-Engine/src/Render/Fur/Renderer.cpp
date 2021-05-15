#include "Renderer.h"

void furRender()
{
	DrawCall* drawcall;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < firstCommandBuffer->size(); i++)
	{
		if (firstCommandBuffer->front() != nullptr)
		{
			drawcall = firstCommandBuffer->front();
			drawcall->draw();
			firstCommandBuffer->pop();
		}
	}

	glfwSwapBuffers(furWindow);
	glfwPollEvents();
}

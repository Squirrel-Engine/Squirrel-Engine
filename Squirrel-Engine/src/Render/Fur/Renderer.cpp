#include "Renderer.h"

void furRender()
{
	DrawCall* drawcall;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	int size = firstCommandBuffer->size();
	for (int i = 0; i <size; i++)
	{
		if (!firstCommandBuffer->empty())
		{
			drawcall = firstCommandBuffer->front();
			drawcall->draw();
			firstCommandBuffer->pop();
		}
	}
	/*std::queue<DrawCall*>* wipeQueue = new std::queue<DrawCall*>;
	std::swap(firstCommandBuffer, wipeQueue);*/

	glfwSwapBuffers(furWindow);
	glfwPollEvents();
}

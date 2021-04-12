#include "Renderer.h"
#include <queue>
#include <thread>
void furRender()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	for (int i = 0; i < firstCommandBuffer->size(); i++) {
		DrawCall* drawcall = firstCommandBuffer->front();
		if(drawcall != nullptr)
		{
			try
			{
				drawcall->model->Draw(*drawcall->shader, drawcall->uniformDesc);
				firstCommandBuffer->pop();
				delete drawcall;
			}
			catch (std::exception& e)
			{
				
			}


		}
	}
	glfwSwapBuffers(furWindow);
	glfwPollEvents();
}

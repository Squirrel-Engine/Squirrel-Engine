#include "Renderer.h"

void furRender()
{
	double lastTime = glfwGetTime();
	int nbFrames = 0;
	// Render All Commands in FirstBuffer : LOOP
	while(firstCommandBuffer->empty() == false)
	{
		/// Measure speed
		double currentTime = glfwGetTime();
		nbFrames++;
		if (currentTime - lastTime >= 1.0) {
			printf("%f ms/frame\n", 1000.0 / double(nbFrames));
			nbFrames = 0;
			lastTime += 1.0;
		}
		/////////////////
	
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		firstCommandBuffer->front()->model->Draw(firstCommandBuffer->front()->shader);

		glfwSwapBuffers(furWindow);
		glfwPollEvents();
	}
	// Render All Commands in Post Process Buffer: LOOP
}
#include "include/Renderer.h"

void furRender()
{
	// Render All Commands in FirstBuffer : LOOP

	int i = 0;
	while(firstCommandBuffer->empty() == false)
	{
		firstCommandBuffer->front()->texture->bind(0);
		firstCommandBuffer->front()->shader->use();
		firstCommandBuffer->front()->vertexArray->bind();

		// create transformations

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));

		EditorCamera camera;
		// pass them to the shaders 
		firstCommandBuffer->front()->shader->setMat4("model", model);
		firstCommandBuffer->front()->shader->setMat4("viewProjection", camera.getViewProjection());

		glEnable(GL_DEPTH_TEST);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 36);


		glfwSwapBuffers(furWindow);
		glfwPollEvents();
		i++;
	}
	printf("%d", i);
	
	// Render All Commands in Post Process Buffer: LOOP













	




	
}
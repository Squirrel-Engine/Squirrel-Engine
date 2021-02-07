#include "Renderer.h"
EditorCamera camera;

void furRender()
{
	// Render All Commands in FirstBuffer : LOOP
	while(firstCommandBuffer->empty() == false)
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		firstCommandBuffer->front()->texture->bind(0);
		firstCommandBuffer->front()->shader->use();
		firstCommandBuffer->front()->vertexArray->bind();
		firstCommandBuffer->front()->shader->setMat4("viewProjection", camera.getViewProjection());

		glDrawArrays(GL_TRIANGLES, 0, 36);
		glm::vec3 cubePositions[] = {
			glm::vec3(0.0f,  0.0f,  0.0f),
			glm::vec3(-1.7f,  3.0f, -7.5f),
			glm::vec3(1.3f, -2.0f, -2.5f),
			glm::vec3(1.5f,  2.0f, -2.5f),
		};
		
		for (unsigned int i = 0; i < 4; i++)
		{
			// calculate the model matrix for each object and pass it to shader before drawing
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, cubePositions[i]);
			model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
		
			glm::vec3 lightPos(0.3f, 0.3f, 1.0f);
			firstCommandBuffer->front()->shader->setMat4("model", model);
			firstCommandBuffer->front()->shader->setVec3("objectColor", 1.0f, 0.5f, 0.31f);
			firstCommandBuffer->front()->shader->setVec3("lightColor", 1.0f, 1.0f, 1.0f);
			firstCommandBuffer->front()->shader->setVec3("lightPos", lightPos);
			firstCommandBuffer->front()->shader->setVec3("viewPos", camera.getPosition());
	
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		glfwSwapBuffers(furWindow);
		glfwPollEvents();
	}
	
	// Render All Commands in Post Process Buffer: LOOP
}
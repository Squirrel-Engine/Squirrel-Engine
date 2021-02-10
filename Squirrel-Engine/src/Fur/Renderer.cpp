#include "Renderer.h"
EditorCamera camera;

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

		// scene light properties
		glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
		glm::vec3 lightPos(0.3f, 0.3f, 1.0f);
		
		firstCommandBuffer->front()->shader->setVec3("light.position", lightPos);
		firstCommandBuffer->front()->shader->setVec3("light.ambient", 0.2f, 0.2f, 0.2f); // we have full control over the lightning. We can change the ambient, diffuse, specular components
		firstCommandBuffer->front()->shader->setVec3("light.diffuse", lightColor);
		firstCommandBuffer->front()->shader->setVec3("light.specular", glm::vec3(1.0f));
		firstCommandBuffer->front()->shader->setVec3("viewPos", camera.getPosition());

		//pass view projection matrices to the shader
		firstCommandBuffer->front()->shader->setMat4("viewProjection", camera.getViewProjection());

		//bind vertex array
		firstCommandBuffer->front()->vertexArray->bind();

		//add 4 cubes
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
		
			firstCommandBuffer->front()->shader->setMat4("model", model);
			
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		glfwSwapBuffers(furWindow);
		glfwPollEvents();
	}
	
	// Render All Commands in Post Process Buffer: LOOP
}
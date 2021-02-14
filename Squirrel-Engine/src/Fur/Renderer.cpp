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

		//set transformation and rotation
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -50.0f));
		model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.8f, 0.8f, 0.8f));

		// scene light properties
		glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
		glm::vec3 lightPos(0.3f, 0.3f, 1.0f);

		firstCommandBuffer->front()->shader->setVec3("light.position", lightPos);
		firstCommandBuffer->front()->shader->setVec3("light.ambient", 0.2f, 0.2f, 0.2f); // we have full control over the lightning. We can change the ambient, diffuse, specular components
		firstCommandBuffer->front()->shader->setVec3("light.diffuse", lightColor);
		firstCommandBuffer->front()->shader->setVec3("light.specular", glm::vec3(1.0f));
		firstCommandBuffer->front()->shader->setVec3("viewPos", camera->getPosition());

		//pass MVP matrices to the shader
		firstCommandBuffer->front()->shader->setMat4("viewProjection", camera->getViewProjection());
		firstCommandBuffer->front()->shader->setMat4("model", model);
	
		firstCommandBuffer->front()->model->Draw();
		
		glfwSwapBuffers(furWindow);
		glfwPollEvents();
	}
	// Render All Commands in Post Process Buffer: LOOP
}
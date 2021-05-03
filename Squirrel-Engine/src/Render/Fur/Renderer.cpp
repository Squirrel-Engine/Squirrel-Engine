#include "Renderer.h"
#include <queue>
#include <InterfaceFactory.h>
#include "glm/glm.hpp"
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
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
	
	GLuint* shader = &getInterface<RM_Interface>().getShader(1)->ID;
	glUseProgram(*shader);

	glUniform3f(glGetUniformLocation(*shader, "view_pos"), 0,0,0);
	glUniform1f(glGetUniformLocation(*shader, "material.shininess"), 32.0f);
	glUniform1f(glGetUniformLocation(*shader, "material.transparency"), 1.0f);
	// Point Light 1
	glUniform3f(glGetUniformLocation(*shader, "point_light.position"), 0,0,0);

	glUniform3f(glGetUniformLocation(*shader, "point_light.ambient"), 0.1f, 0.1f, 0.1f);
	glUniform3f(glGetUniformLocation(*shader, "point_light.diffuse"), 1.0f, 1.0f, 1.0f);
	glUniform3f(glGetUniformLocation(*shader, "point_light.specular"), 1.0f, 1.0f, 1.0f);

	glUniform1f(glGetUniformLocation(*shader, "point_light.constant"), 1.0f);
	glUniform1f(glGetUniformLocation(*shader, "point_light.linear"), 0.007);	
	glUniform1f(glGetUniformLocation(*shader, "point_light.quadratic"), 0.0002);

	glm::mat4 MVP;
	glm::mat4 perspective_view = mat4(1.0f);
	glm::mat4 perspective_projection = perspective(radians(60.0f), 1.7f, 0.1f, 100.0f);
	glm::mat4 matr_model_1 = mat4(1);
	matr_model_1 = glm::translate(matr_model_1, vec3(0,0,-30));
	matr_model_1 = glm::rotate(matr_model_1, glm::radians(10.0f), glm::vec3(0.0f, 0.0f, 1.0f));

	MVP = perspective_projection * perspective_view * matr_model_1;
	glUniformMatrix4fv(glGetUniformLocation(*shader, "MVP"), 1, GL_FALSE, glm::value_ptr(MVP));
	glUniformMatrix4fv(glGetUniformLocation(*shader, "M_matrix"), 1, GL_FALSE, glm::value_ptr(matr_model_1));
	glm::mat4 matr_normals_cube = glm::mat4(glm::transpose(glm::inverse(matr_model_1)));
	glUniformMatrix4fv(glGetUniformLocation(*shader, "normals_matrix"), 1, GL_FALSE, glm::value_ptr(matr_normals_cube));
	getInterface<RM_Interface>().getSkeletalModel(0)->Draw(getInterface<RM_Interface>().getShader(1));
	
	glfwSwapBuffers(furWindow);
}

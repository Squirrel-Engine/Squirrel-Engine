// Squirrel-Engine.cpp : Defines the entry point for the application.
//
#include "../Squirrel-Engine/include/Squirrel.h"
#include "../../Squirrel-Engine/include/Mesh.h"

class Sandbox : public Squirrel::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

	virtual void Run() override;
	

};

Squirrel::Application* Squirrel::CreateApplication()
{
	return new Sandbox();
}

void Sandbox::Run() 
{
	//DrawCall(Model, Shader)
	Shader shader("../../Squirrel-Engine/res/shaders/Model.shader");
	//set transformation and rotation
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -50.0f));
	//model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.8f, 0.8f, 0.8f));
	shader.uniforms.model = model;
	shader.uniforms.viewPos = camera->getPosition();
	shader.uniforms.viewProjection = camera->getViewProjection();

	DrawCall* drawCall = new DrawCall("../../Squirrel-Engine/res/models/sword/sword.obj",
									   shader);

	Squirrel::InterfaceFactory::getInstance()->getRDInterface()->submitDrawCall(drawCall);
}


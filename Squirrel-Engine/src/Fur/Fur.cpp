#include "include/Fur.h"

#include "include/FurStore.h"

namespace Fur
{	
	Fur::Fur()
	{

	}

	void Fur::startRenderEngine()
	{
		//access all rendering options
		Squirrel::RenderConfig config = Squirrel::Configuration::getInstance()->renderConfig;
		
		//start
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		
		furWindow =  glfwCreateWindow(config.screenWidth, config.screenHeight, config.windowName.c_str(), NULL, NULL);
		if (furWindow == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}
		glfwMakeContextCurrent(furWindow);

		// glad: load all OpenGL function pointers
		// ---------------------------------------
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			glfwTerminate();
		}
		glViewport(0, 0, config.screenWidth, config.screenHeight);
		
		glBindVertexArray(0);

		firstCommandBuffer = new std::queue<DrawCall*>;

		submitDrawCall();
		submitDrawCall();
		submitDrawCall();
	}

	void Fur::pauseRenderEngine()
	{
		
	}

	void Fur::stopRenderEngine()
	{
		
	}

	void Fur::render()
	{
		furRender();
	}

	void Fur::addActorToRenderQueue()
	{
		render();
	}

	void Fur::submitDrawCall()
	{
		float vertices[] = {
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
		};
		DrawCall* drawCall = new DrawCall();
		
		std::shared_ptr<VertexArray> vertexArray;
		std::shared_ptr<VertexBuffer> vertexBuffer;
		std::shared_ptr<Texture> texture;
		std::shared_ptr<Shader> shader;
		
		vertexArray.reset(VertexArray::Create());
		vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
		BufferLayout layout = {
			{ShaderDataType::Float3, "pos"},
			{ShaderDataType::Float2, "texCoor"}
		};
		vertexBuffer->setLayout(layout);
		vertexArray->addVertexBuffer(vertexBuffer);

		texture.reset(new Texture("../../Squirrel-Engine/res/textures/wall.jpg"));
		shader.reset(new Shader("../../Squirrel-Engine/res/shaders/Basic.shader"));
		shader->setInt("texture1", 0);

		drawCall->vertexBuffer = vertexBuffer;
		drawCall->vertexArray = vertexArray;
		drawCall->shader = shader;
		drawCall->texture = texture;

		firstCommandBuffer->push(drawCall);
		
	}

	GLFWwindow* Fur::getGlfwWindow()
	{
		return furWindow;
	}

	void Fur::updateRenderEngineOptions(std::string parameterName, int parameter)
	{
		
	}

	void Fur::updateRenderEngineOptions(std::string parameterName, float parameter)
	{
		
	}

	void Fur::updateRenderEngineOptions(std::string parameterName, std::string parameter)
	{
		
	}

}

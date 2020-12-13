#pragma once
#include <queue>
#include "GLFW/glfw3.h"
#include "RenderObject/Shader.h"
#include "RenderObject/VertexArray.h"
#include "RenderObject/VertexBuffer.h"
#include "RenderObject/VertexBufferLayout.h"
#include "RenderObject/IndexBuffer.h"

struct RenderObject
{
	VertexArray va; 
	VertexBuffer vb;
	VertexBufferLayout layout;
	IndexBuffer ib;
	Shader shader;
};
//
//
//std::vector<RenderObject>* renderVector;
extern GLFWwindow* furWindow;

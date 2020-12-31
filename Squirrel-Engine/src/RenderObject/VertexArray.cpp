#include "include/RenderObject/VertexArray.h"
#include "include/OpenGL/OpenGLVertexArray.h"

VertexArray* VertexArray::VertexArray::Create()
{
	return new OpenGLVertexArray();
}


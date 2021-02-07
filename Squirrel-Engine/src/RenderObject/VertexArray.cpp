#include "VertexArray.h"
#include "OpenGLVertexArray.h"

VertexArray* VertexArray::VertexArray::Create()
{
	//TODO:Render API base implementation
	return new OpenGLVertexArray();
}


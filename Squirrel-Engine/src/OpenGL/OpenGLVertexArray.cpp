#include "include/OpenGL/OpenGLVertexArray.h"

OpenGLVertexArray::OpenGLVertexArray()
{
	glGenVertexArrays(1, &m_RendererID);
}

void OpenGLVertexArray::bind() const
{
	glBindVertexArray(m_RendererID);
}

void OpenGLVertexArray::unnbind() const
{
	glBindVertexArray(0);
}

void OpenGLVertexArray::addVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
{
	glBindVertexArray(m_RendererID);
	vertexBuffer->bind();
	const auto& layout = vertexBuffer->getLayout();
	const auto& elements = layout.getElements();
	unsigned int offset = 0;
	for (int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, 
			element.getElementCount(),
			ShaderDataTypetoOpenGLBaseType(element.type), 
			element.normalized ? GL_TRUE : GL_FALSE,
			layout.getStride(), 
			(const void*)element.offset);
	}
	m_VertexBuffer.push_back(vertexBuffer);
}

void OpenGLVertexArray::setIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
{
	glBindVertexArray(m_RendererID);
	indexBuffer->bind();

	//m_IndexBuffer.push_back(m_IndexBuffer);
}

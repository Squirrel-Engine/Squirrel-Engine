#pragma once
#include "include/VertexArray.h"

class OpenGLVertexArray : public VertexArray {
public:
	OpenGLVertexArray();
	virtual ~OpenGLVertexArray();

	virtual void bind() const override;
	virtual void unnbind() const override;

	void addVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;
	void setIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) override;
private:
	unsigned int m_RendererID;
	std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffer;
	//std::vector<std::shared_ptr<IndexBuffer>> m_IndexBuffer;
};

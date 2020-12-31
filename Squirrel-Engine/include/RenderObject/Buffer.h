#pragma once
#include <vector>
#include <glad/glad.h>
#include <string>
#include <iostream>

enum class ShaderDataType {
	None = 0, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool
};

static GLenum ShaderDataTypetoOpenGLBaseType(ShaderDataType type) {
	switch (type)
	{
	case ShaderDataType::Float:		return GL_FLOAT;
	case ShaderDataType::Float2:	return GL_FLOAT;
	case ShaderDataType::Float3:	return GL_FLOAT;
	case ShaderDataType::Float4:	return GL_FLOAT;
	case ShaderDataType::Mat3:		return GL_FLOAT;
	case ShaderDataType::Mat4:		return GL_FLOAT;
	case ShaderDataType::Int:		return GL_INT;
	case ShaderDataType::Int2:		return GL_INT;
	case ShaderDataType::Int3:		return GL_INT;
	case ShaderDataType::Int4:		return GL_INT;
	case ShaderDataType::Bool:		return GL_BOOL;
	default:
		std::cout << "Unknown data type!" << std::endl;	return 0;
	}
}

static unsigned int	ShaderDataTypeSize(ShaderDataType type) {
	switch (type)
	{
	case ShaderDataType::Float:		return 4;
	case ShaderDataType::Float2:	return 8;
	case ShaderDataType::Float3:	return 12;
	case ShaderDataType::Float4:	return 16;
	case ShaderDataType::Mat3:		return 36;
	case ShaderDataType::Mat4:		return 64;
	case ShaderDataType::Int:		return 4;
	case ShaderDataType::Int2:		return 8;
	case ShaderDataType::Int3:		return 12;
	case ShaderDataType::Int4:		return 16;
	case ShaderDataType::Bool:		return 1;
	default:	
		std::cout << "Unknown data type!" << std::endl;	return 0;
	}
}

struct BufferElement
{
	std::string name;
	ShaderDataType type;
	unsigned int size;
	unsigned char offset;
	bool normalized;

	BufferElement(ShaderDataType _type, const std::string& _name)
		:name(_name), type(_type), size(ShaderDataTypeSize(type)), offset(0), normalized(false)
	{
	}	
	unsigned int getElementCount() const {
		switch (type)
		{
		case ShaderDataType::Float:		return 1;
		case ShaderDataType::Float2:	return 2;
		case ShaderDataType::Float3:	return 3;
		case ShaderDataType::Float4:	return 4;
		case ShaderDataType::Mat3:		return 9;
		case ShaderDataType::Mat4:		return 16;
		case ShaderDataType::Int:		return 1;
		case ShaderDataType::Int2:		return 2;
		case ShaderDataType::Int3:		return 3;
		case ShaderDataType::Int4:		return 4;
		case ShaderDataType::Bool:		return 1;
		default:
			break;
		}
	}
};

class BufferLayout {
public:
	BufferLayout() {}
	BufferLayout(const std::initializer_list<BufferElement>& elements)
		:m_Elemets(elements) 
	{
		CalculateOffsetAndStride();
	}

	inline const std::vector<BufferElement> getElements() const { return m_Elemets; }
	inline const unsigned int getStride() const { return m_Stride; }

private:
	std::vector<BufferElement> m_Elemets;
	unsigned int m_Stride = 0;

	void CalculateOffsetAndStride() {
		unsigned int offset = 0;
		m_Stride = 0;
		for (auto& element : m_Elemets)
		{
			element.offset = offset;
			offset += element.size;
			m_Stride += element.size;
		}
	}
};

class VertexBuffer
{
public:
	virtual ~VertexBuffer() {}

	virtual void bind() const = 0;
	virtual void unbind() const = 0;

	virtual const BufferLayout& getLayout() const = 0;
	virtual void setLayout(const BufferLayout& layout) = 0;

	static VertexBuffer* Create(const void* data, unsigned int size);
};

class IndexBuffer
{
public:
	virtual ~IndexBuffer() {}

	virtual void bind() const = 0;
	virtual void unbind() const = 0;

	static IndexBuffer* Create(const void* data, unsigned int size);
};

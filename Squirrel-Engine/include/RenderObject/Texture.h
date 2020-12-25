#pragma once
#include <string>
#include <glad/glad.h>

class Texture
{
private:
	unsigned int m_RendererID;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;
public:
	Texture(const std::string& path);
	~Texture();

	void bind(unsigned int slot) const;
	void unbind() const;

	inline int getWidht() const { return m_Width; }
	inline int getHeight() const { return m_Height; }
};
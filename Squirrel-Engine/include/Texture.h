#pragma once
#include <string>

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

	unsigned int getID() const { return m_RendererID; }
	//inline unsigned int getPath() const { return  }  // This will return texture file name
	int getWidht() const { return m_Width; }
	int getHeight() const { return m_Height; }
};

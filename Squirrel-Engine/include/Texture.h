#pragma once
#include <string>
#include <glad/glad.h>

class Texture
{
public:
	Texture() {}
	~Texture() {}

	unsigned int loadTexture(char const* path) const;
	void bind(unsigned int slot, unsigned int id) const;
	void unbind() const;
	
};
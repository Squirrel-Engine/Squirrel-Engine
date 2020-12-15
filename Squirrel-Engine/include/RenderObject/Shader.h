#pragma once
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    struct ShaderProgramSource
    {
        std::string VertexSource;
        std::string FragmentSource;
    };
    enum class ShaderType{ NONE = -1, VERTEX = 0, FRAGMENT = 1 };
    unsigned int ID;

    Shader(const std::string& filepath);
    ~Shader();
	
	void use();

	// utility uniform functions
    void setBool(const std::string& name, bool value) const;
	
    void setInt(const std::string& name, int value) const;
	
    void setFloat(const std::string& name, float value) const;
    

private:
    void checkCompileErrors(unsigned int shader, std::string type);
};
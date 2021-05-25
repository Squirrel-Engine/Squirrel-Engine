#include "Shader.h"

Shader::Shader(const std::string& filepath)
{
	ShaderProgramSource source;
	std::fstream stream(filepath);
	std::string line;
	std::stringstream ss[2];
	auto type = ShaderType::NONE;

	while (std::getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				type = ShaderType::FRAGMENT;
			}
		}
		else
		{
			ss[static_cast<int>(type)] << line << '\n';
		}
	}
	source.VertexSource = ss[0].str();
	source.FragmentSource = ss[1].str();

	// 2. compile shaders
	// vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	const char* vertexSrc = source.VertexSource.c_str();
	glShaderSource(vertex, 1, &vertexSrc, nullptr);
	glCompileShader(vertex);
	checkCompileErrors(vertex, "VERTEX");

	// fragment Shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fragmentSrc = source.FragmentSource.c_str();
	glShaderSource(fragment, 1, &fragmentSrc, nullptr);
	glCompileShader(fragment);
	checkCompileErrors(fragment, "FRAGMENT");

	// shader Program
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	checkCompileErrors(ID, "PROGRAM");

	// delete the shaders as they're linked into our program now and no longer necessary
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::use()
{
	glUseProgram(ID);
}

GLint Shader::getUniformLocation(const std::string& name) const
{
	if (m_UniformCache.find(name) != m_UniformCache.end())
		return m_UniformCache[name];
	GLint location = glGetUniformLocation(ID, name.c_str());
	if (location == -1)
		std::cout << "Warning: Uniform " << name << " does not exist!" << std::endl;
	m_UniformCache[name] = location;
	return location;
}

// uniforms --------------------------------------------------------
void Shader::setBool(const std::string& name, bool value) const
{
	glUniform1i(getUniformLocation(name), static_cast<int>(value));
}

// ------------------------------------------------------------------------
void Shader::setInt(const std::string& name, int value) const
{
	glUniform1i(getUniformLocation(name), value);
}

// ------------------------------------------------------------------------
void Shader::setFloat(const std::string& name, float value) const
{
	glUniform1f(getUniformLocation(name), value);
}

// ------------------------------------------------------------------------
void Shader::setVec2(const std::string& name, const vec2& value) const
{
	glUniform2fv(getUniformLocation(name), 1, &value[0]);
}

void Shader::setVec2(const std::string& name, float x, float y) const
{
	glUniform2f(getUniformLocation(name), x, y);
}

// ------------------------------------------------------------------------
void Shader::setVec3(const std::string& name, const vec3& value) const
{
	glUniform3fv(getUniformLocation(name), 1, &value[0]);
}

void Shader::setVec3(const std::string& name, float x, float y, float z) const
{
	glUniform3f(getUniformLocation(name), x, y, z);
}

// ------------------------------------------------------------------------
void Shader::setVec4(const std::string& name, const vec4& value) const
{
	glUniform4fv(getUniformLocation(name), 1, &value[0]);
}

void Shader::setVec4(const std::string& name, float x, float y, float z, float w) const
{
	glUniform4f(getUniformLocation(name), x, y, z, w);
}

void Shader::setIVec4(const std::string& name, const ivec4& value) const
{
	glUniform4iv(getUniformLocation(name), 1, &value[0]);
}

// ------------------------------------------------------------------------
void Shader::setMat2(const std::string& name, const mat2& mat) const
{
	glUniformMatrix2fv(getUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
}

// ------------------------------------------------------------------------
void Shader::setMat3(const std::string& name, const mat3& mat) const
{
	glUniformMatrix3fv(getUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
}

// ------------------------------------------------------------------------
void Shader::setMat4(const std::string& name, const mat4& mat) const
{
	glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
}

void Shader::checkCompileErrors(unsigned int shader, std::string type)
{
	int success;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog <<
				"\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog <<
				"\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
}

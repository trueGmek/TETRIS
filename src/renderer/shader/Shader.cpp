#include "Shader.h"

Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath)
{
	const char* vertexCode = ReadShader(vertexShaderPath);
	const char* fragmentCode = ReadShader(fragmentShaderPath);

	unsigned int vertex, fragment;
	LoadShader(&vertex, GL_VERTEX_SHADER, vertexCode);
	LoadShader(&fragment, GL_FRAGMENT_SHADER, fragmentCode);

	ID = glCreateProgram();
	glAttachShader(vertex, GL_VERTEX_SHADER);
	glAttachShader(fragment, GL_FRAGMENT_SHADER);
	glLinkProgram(ID);

	CheckLinking(ID);

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

const char* Shader::ReadShader(const char* pathToShader)
{
	char* code;
	std::ifstream fileStream;
	fileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		std::stringstream stringStream;
		fileStream.open(pathToShader);
		stringStream << fileStream.rdbuf();

		std::string codeString = stringStream.str();

		std::memcpy(code, codeString.c_str(), codeString.size() + 1);
		return code;

	}
	catch (std::ifstream::failure& e)
	{
		std::cout << "ERROR::SHADER::FILE_UNSUCCESSFULLY_READ:: " << pathToShader << std::endl;
	}
}

void Shader::LoadShader(unsigned int* shader, GLenum type, const char* shaderSource)
{
	std::string typeString = type == GL_FRAGMENT_SHADER ? "GL_FRAGMENT_SHADER" : "GL_VERTEX_SHADER";

	if (!CompileShader(shader, type, shaderSource))
	{
		char infoLog[512];
		glGetShaderInfoLog(*shader, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::" << typeString << "::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

}

int Shader::CompileShader(unsigned int* shader, GLenum type, const char* shaderSource)
{
	*shader = glCreateShader(type);

	glShaderSource(*shader, 1, &shaderSource, nullptr);
	glCompileShader(*shader);

	int success;
	glGetShaderiv(*shader, GL_COMPILE_STATUS, &success);

	return success;
}

void Shader::Use()
{
	glUseProgram(ID);
}

void Shader::CheckLinking(unsigned int id)
{
	int success;
	char infoLog[512];

	glGetProgramiv(id, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(ID, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
}

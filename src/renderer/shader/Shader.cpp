#include "Shader.h"

Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
	const std::string* vertexCode = ReadShader(vertexShaderPath);
	const std::string* fragmentCode = ReadShader(fragmentShaderPath);

	unsigned int vertex, fragment;
	LoadShader(&vertex, GL_VERTEX_SHADER, *vertexCode);
	LoadShader(&fragment, GL_FRAGMENT_SHADER, *fragmentCode);

	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);

	CheckLinking(ID);

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

std::string* Shader::ReadShader(const std::string& pathToShader)
{
	auto* code = new std::string();
	std::ifstream fileStream;
	fileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		std::stringstream stringStream;
		fileStream.open(pathToShader);
		stringStream << fileStream.rdbuf();

		std::string codeString = stringStream.str();

		*code = codeString;
		return code;
	}
	catch (std::ifstream::failure& e)
	{
		std::cout << "ERROR::SHADER::FILE_UNSUCCESSFULLY_READ:: " << pathToShader << std::endl;
	}

	return nullptr;
}

void Shader::LoadShader(unsigned int* shader, GLenum type, const std::string& shaderSource)
{
	std::string typeString = type == GL_FRAGMENT_SHADER ? "GL_FRAGMENT_SHADER" : "GL_VERTEX_SHADER";

	if (!CompileShader(shader, type, shaderSource))
	{
		char infoLog[512];
		glGetShaderInfoLog(*shader, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::" << typeString << "::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

}

int Shader::CompileShader(unsigned int* shader, GLenum type, const std::string& shaderSource)
{
	*shader = glCreateShader(type);

	const char* shaderCode = shaderSource.c_str();
	glShaderSource(*shader, 1, &shaderCode, nullptr);
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
	int status;
	char infoLog[512];

	glGetProgramiv(id, GL_LINK_STATUS, &status);

	if (status == GL_FALSE)
	{
		glGetProgramInfoLog(ID, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
}

#ifndef TETRIS_SRC_RENDERER_SHADER_SHADER_H
#define TETRIS_SRC_RENDERER_SHADER_SHADER_H

#include "glad/glad.h"

#include <sstream>
#include <istream>
#include <fstream>
#include <iostream>
#include <cstring>

class Shader
{
public:
	unsigned int ID;
	Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	void Use();
private:
	static void LoadShader(unsigned int* shader, GLenum type, const std::string& shaderSource);
	static int CompileShader(unsigned int* shader, GLenum type, const std::string& shaderSource);
	static std::string* ReadShader(const std::string& pathToShader);
	void CheckLinking(unsigned int id);
};

#endif //TETRIS_SRC_RENDERER_SHADER_SHADER_H

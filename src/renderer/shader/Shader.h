#ifndef TETRIS_SRC_RENDERER_SHADER_SHADER_H
#define TETRIS_SRC_RENDERER_SHADER_SHADER_H

#include "glad/glad.h"
#include "glm/ext/matrix_float4x4.hpp"

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

	void SetMat4Uniform(const std::string& name, glm::mat4 value) const;
	void SetVec4Uniform(const std::string& name, glm::vec4 value) const;
private:
	static void LoadShader(unsigned int* shader, GLenum type, const std::string& shaderSource);
	static int CompileShader(unsigned int* shader, GLenum type, const std::string& shaderSource);
	static std::string* ReadShader(const std::string& pathToShader);
	void CheckLinking(unsigned int id);
};

#endif //TETRIS_SRC_RENDERER_SHADER_SHADER_H

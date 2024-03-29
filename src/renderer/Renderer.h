#pragma once

#define GLFW_INCLUDE_NONE

#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "camera/Camera.h"
#include "primitives/Primitive.h"
#include "queue"

namespace Renderer
{
	extern GLFWwindow* window;

	const int kInitialWidth{ 800 };
	const int kInitialHeight{ 800 };

	extern float windowWidth;
	extern float windowHeight;

	bool Initialize();
	void Terminate();
	void Update();
	bool IsWindowClosing();
	void GenerateCharacterTextures();
}

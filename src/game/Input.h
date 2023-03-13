#pragma once

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <iostream>

class Input
{
public:
	static bool Initialize();

	static void InputKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	static void SetKeyScancodes();
};

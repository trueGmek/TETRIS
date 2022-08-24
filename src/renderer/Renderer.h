#ifndef TETRIS_SRC_RENDERER_RENDERER_H
#define TETRIS_SRC_RENDERER_RENDERER_H

#include <iostream>

#define GLFW_INCLUDE_NONE

#include "GLFW/glfw3.h"
#include "glad/glad.h"


const int InitialWidth = 640;
const int InitialHeight = 480;

namespace Renderer
{
	bool Initialize();
	void Terminate();
	void Update();
	bool IsWindowClosing();
}

#endif //TETRIS_SRC_RENDERER_RENDERER_H

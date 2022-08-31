#ifndef TETRIS_SRC_RENDERER_RENDERER_H
#define TETRIS_SRC_RENDERER_RENDERER_H

#define GLFW_INCLUDE_NONE

#include <iostream>
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "../camera/Camera.h"
#include "primitives/Primitive.h"
#include "queue"

const int INITIAL_WIDTH{ 640 };
const int INITIAL_HEIGHT{ 480 };

namespace Renderer
{
	extern std::queue<Renderer::Primitive*> _primitivesQueue;

	bool Initialize();
	void Terminate();
	void Update();
	bool IsWindowClosing();
}

#endif //TETRIS_SRC_RENDERER_RENDERER_H

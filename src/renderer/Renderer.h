#ifndef TETRIS_SRC_RENDERER_RENDERER_H_
#define TETRIS_SRC_RENDERER_RENDERER_H_

#define GLFW_INCLUDE_NONE

#include <iostream>
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "../camera/Camera.h"
#include "primitives/Primitive.h"
#include "queue"

const int kInitialWidth{640};
const int kInitialHeight{480};

namespace renderer {
extern GLFWwindow *window;

bool Initialize();
void Terminate();
void Update();
bool IsWindowClosing();
}

#endif //TETRIS_SRC_RENDERER_RENDERER_H_

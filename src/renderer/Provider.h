#ifndef TETRIS_SRC_RENDERER_PROVIDER_H_
#define TETRIS_SRC_RENDERER_PROVIDER_H_

#include <vector>

#include "primitives/Primitive.h"
#include "primitives/cube/Cube.h"

namespace renderer {

extern std::vector<renderer::Primitive *> primitivesList;

//TODO: SUBSTITUTE EXPLICIT FUNCTIONS FOR ONE TEMPLATE FUNCTION
renderer::Cube *CreateCube();

} // Renderer

#endif //TETRIS_SRC_RENDERER_PROVIDER_H_

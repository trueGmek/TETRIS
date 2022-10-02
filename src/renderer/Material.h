#ifndef TETRIS_SRC_RENDERER_MATERIAL_H_
#define TETRIS_SRC_RENDERER_MATERIAL_H_

#include "glm/vec4.hpp"

struct Material {
  glm::vec4 color{0};
  explicit Material() = default;
  explicit Material(const glm::vec4 &color) : color(color) {}
};

#endif //TETRIS_SRC_RENDERER_MATERIAL_H_

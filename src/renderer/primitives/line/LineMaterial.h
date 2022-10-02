#ifndef TETRIS_SRC_RENDERER_PRIMITIVES_LINE_LINEMATERIAL_H_
#define TETRIS_SRC_RENDERER_PRIMITIVES_LINE_LINEMATERIAL_H_

#include "../../Material.h"

struct LineMaterial : Material {
 public :
  float width{};
  LineMaterial() = default;
  LineMaterial(const glm::vec4 &color, float width) : Material(color), width(width) {}
};

#endif //TETRIS_SRC_RENDERER_PRIMITIVES_LINE_LINEMATERIAL_H_

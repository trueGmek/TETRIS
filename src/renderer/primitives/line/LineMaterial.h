#ifndef TETRIS_SRC_RENDERER_PRIMITIVES_LINE_LINEMATERIAL_H_
#define TETRIS_SRC_RENDERER_PRIMITIVES_LINE_LINEMATERIAL_H_

#include "../../Material.h"

struct LineMaterial : Material {
 public :
  float width{};
};

#endif //TETRIS_SRC_RENDERER_PRIMITIVES_LINE_LINEMATERIAL_H_

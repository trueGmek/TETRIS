#ifndef TETRIS_SRC_GAME_GRID_H_
#define TETRIS_SRC_GAME_GRID_H_

#include "GameObject.h"
#include "../renderer/primitives/line/Line.h"

class Grid : GameObject {
 private:
  renderer::Line *left_;
  renderer::Line *top_;
  renderer::Line *right_;
  renderer::Line *bottom_;
 public:

  Grid();
  ~Grid() override {};

  void OnEnable() override {};

  void Start() override {};

  void Update() override {};

  void OnDisable() override {};

  void OnDestroy() override {};
};

#endif //TETRIS_SRC_GAME_GRID_H_

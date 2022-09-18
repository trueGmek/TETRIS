#ifndef TETRIS_SRC_GAME_MOVINGCUBE_H_
#define TETRIS_SRC_GAME_MOVINGCUBE_H_

#include "GameCube.h"

class MovingCube : GameObject {
 public:

  renderer::Cube *renderer_;

  MovingCube();
  ~MovingCube() override;

  void OnEnable() override {}

  void Start() override {}

  void Update() override;

  void OnDisable() override {}

  void OnDestroy() override {}
};

#endif //TETRIS_SRC_GAME_MOVINGCUBE_H_

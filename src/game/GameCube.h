#ifndef TETRIS_SRC_GAME_GAMECUBE_H_
#define TETRIS_SRC_GAME_GAMECUBE_H_

#include "../renderer/primitives/cube/Cube.h"
#include "GameObject.h"

class GameCube : public GameObject {
 public:
  GameCube();
  ~GameCube() override;

  renderer::Cube *renderer_;

  void OnEnable() override {}

  void Start() override {}

  void Update() override {
	renderer_->SetTransform(transform_);
  }

  void OnDisable() override {}

  void OnDestroy() override {}

};

#endif //TETRIS_SRC_GAME_GAMECUBE_H_

#ifndef TETRIS_SRC_GAME_GAMECUBE_H_
#define TETRIS_SRC_GAME_GAMECUBE_H_

#include "../renderer/primitives/cube/Cube.h"
#include "GameObject.h"

namespace game {
class GameCube : GameObject {
 public:
  GameCube();
  ~GameCube();

 private:
  renderer::Cube *renderer_;
};

} // Game

#endif //TETRIS_SRC_GAME_GAMECUBE_H_

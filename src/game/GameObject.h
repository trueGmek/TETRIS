#ifndef TETRIS_SRC_GAME_GAMEOBJECT_H_
#define TETRIS_SRC_GAME_GAMEOBJECT_H_

#include "../Transform.h"

class GameObject {
 public:
  Transform transform_{};

  virtual void OnEnable() {
  }

  virtual void Start() {
  }

  virtual void Update() {
  }

  virtual void OnDisable() {
  }

  virtual void OnDestroy() {
  }
};

#endif //TETRIS_SRC_GAME_GAMEOBJECT_H_

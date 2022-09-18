#ifndef TETRIS_SRC_GAME_GAMEOBJECT_H_
#define TETRIS_SRC_GAME_GAMEOBJECT_H_

#include "../Transform.h"

class GameObject {
 public:
  Transform transform_{};

  GameObject();

  virtual ~GameObject() = default;

  virtual void OnEnable() = 0;

  virtual void Start() = 0;

  virtual void Update() = 0;

  virtual void OnDisable() = 0;

  virtual void OnDestroy() = 0;
};
#endif //TETRIS_SRC_GAME_GAMEOBJECT_H_

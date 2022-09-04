#ifndef TETRIS_SRC_CAMERA_CAMERA_H_
#define TETRIS_SRC_CAMERA_CAMERA_H_

#include "../Transform.h"

class Camera {
 public:
  Camera();

  static glm::mat4 ProjectionMatrix();
  static glm::mat4 ViewMatrix();
  static glm::mat4 ScreenToWorld();

 private:
};

#endif //TETRIS_SRC_CAMERA_CAMERA_H_

#include "GameCube.h"

GameCube::GameCube() {
  renderer_ = new renderer::Cube();
}

GameCube::~GameCube() {
  delete this->renderer_;
}

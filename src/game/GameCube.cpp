#include "GameCube.h"
#include "../renderer/Provider.h"

namespace game {
GameCube::GameCube() {
  renderer_ = renderer::CreateCube();
}

GameCube::~GameCube() {
  delete this->renderer_;
}
} // Game
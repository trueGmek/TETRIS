#include "MovingCube.h"

void MovingCube::Update() {
  transform_.position += glm::vec3(0, -0.01, 0);
  renderer_->SetTransform(transform_);
}

MovingCube::MovingCube() {
  renderer_ = new renderer::Cube();
}

MovingCube::~MovingCube() {
  delete this->renderer_;
}

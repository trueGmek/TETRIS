#include "GameCube.h"

GameCube::GameCube() {
	renderer_ = new renderer::Cube();
}

GameCube::~GameCube() {
	delete this->renderer_;
}

void GameCube::Update() {

//  transform_.position = Camera::ScreenToWorld() * glm::vec4(transform_.position, 1.0f);
	renderer_->SetTransform(transform_);
}

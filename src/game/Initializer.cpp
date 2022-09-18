#include "Initializer.h"
#include "GameCube.h"
#include "../renderer/primitives/line/Line.h"
#include "../renderer/primitives/Colors.h"
#include "MovingCube.h"
#include "Grid.h"

GameCube *cube1;
GameCube *cube2;
GameCube *cube3;
GameCube *cube4;

MovingCube *cube5;
Grid *grid;

bool Initializer::Initialize() {
  cube1 = new GameCube();
  cube2 = new GameCube();
  cube3 = new GameCube();
  cube4 = new GameCube();
  cube5 = new MovingCube();

  grid = new Grid();

  LineMaterial line_material;

  line_material.color = colors::WHITE;
  line_material.width = 2.0f;

  cube1->transform_.position = glm::vec3{-1.4, -1, 0};
  cube2->transform_.position = glm::vec3{1.4, 1, 0};
  cube3->transform_.position = glm::vec3{-1.4, 1, 0};
  cube4->transform_.position = glm::vec3{1.4, -1, 0};

  cube1->renderer_->material_.color = colors::RED;
  cube2->renderer_->material_.color = colors::GREEN;
  cube3->renderer_->material_.color = colors::BLUE;
  cube4->renderer_->material_.color = colors::YELLOW;

  return true;
}

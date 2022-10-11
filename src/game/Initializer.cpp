#include "Initializer.h"
#include "GameCube.h"
#include "../renderer/primitives/line/Line.h"
#include "../renderer/primitives/Colors.h"
#include "MovingCube.h"
#include "Grid/Grid.h"

GameCube *cube1;
GameCube *cube2;
GameCube *cube3;
GameCube *cube4;

MovingCube *cube5;
Grid<10, 20> *grid;

bool Initializer::Initialize() {
  cube1 = new GameCube();
  cube2 = new GameCube();
  cube3 = new GameCube();
  cube4 = new GameCube();
  cube5 = new MovingCube();

  grid = new Grid<10, 20>({-0.9, -0.9, 0, 1}, {0, -0.9, 0, 1}, {-0.9, 0.9f, 0, 1}, {0, 0.9f, 0, 1});

  LineMaterial line_material{colors::WHITE, 2.0f};

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

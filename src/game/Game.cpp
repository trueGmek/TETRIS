#include "Game.h"
#include "glm/vec3.hpp"
#include "../renderer/Renderer.h"
#include "../renderer/primitives/line/Line.h"
#include "../renderer/primitives/Colors.h"
#include "../renderer/Provider.h"

renderer::Cube *cube1;
renderer::Cube *cube2;
renderer::Cube *cube3;
renderer::Cube *cube4;

renderer::Line *line1;

bool game::Initialize() {

  cube1 = new renderer::Cube();
  cube2 = new renderer::Cube();
  cube3 = new renderer::Cube();
  cube4 = new renderer::Cube();

  line1 = new renderer::Line();

  return true;
}

void game::Update() {
  Transform transform_1, transform_2, transform_3, transform_4;
  Transform line_start, line_end, line_pivot;

  LineMaterial line_material;

  line_material.color = colors::WHITE;
  line_material.width = 2.0f;

  glm::vec4 start_screen_space = {-0.9, -0.9, 0, 1};
  glm::vec4 end_screen_space = {-0.9, 0.9f, 0, 1};

  transform_1.position = glm::vec3{-1.4, -1, 0};
  transform_2.position = glm::vec3{1.4, 1, 0};
  transform_3.position = glm::vec3{-1.4, 1, 0};
  transform_4.position = glm::vec3{1.4, -1, 0};

  line_start.position = Camera::ScreenToWorld() * start_screen_space;
  line_end.position = Camera::ScreenToWorld() * end_screen_space;
  line_pivot.position = glm::vec3{0, 0, 0};

  cube1->SetTransform(transform_1);
  cube1->material_.color = colors::RED;

  cube2->SetTransform(transform_2);
  cube2->material_.color = colors::GREEN;

  cube3->SetTransform(transform_3);
  cube3->material_.color = colors::BLUE;

  cube4->SetTransform(transform_4);
  cube4->material_.color = colors::YELLOW;

  line1->SetStart(line_start);
  line1->SetEnd(line_end);
  line1->SetPivot(line_pivot);
  line1->material_.color = colors::WHITE;
  line1->material_.width = 2.0f;

  renderer::primitivesList.insert(renderer::primitivesList.end(),
								  {cube1, cube2, cube3, cube4, line1});
}

void game::Terminate() {
  delete cube1;
  delete cube2;
  delete cube3;
  delete cube4;
  delete line1;
}

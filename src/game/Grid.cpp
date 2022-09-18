#include "Grid.h"
#include "../camera/Camera.h"
#include "../renderer/primitives/Colors.h"

Grid::Grid() {

  Transform line_start, line_end, line_pivot;

  glm::vec4 top_left = {-0.9, -0.9, 0, 1};
  glm::vec4 top_right = {-0.5, -0.9, 0, 1};
  glm::vec4 bottom_left = {-0.9, 0.9f, 0, 1};
  glm::vec4 bottom_right = {-0.5, 0.9f, 0, 1};

  line_start.position = Camera::ScreenToWorld() * top_left;
  line_end.position = Camera::ScreenToWorld() * bottom_left;
  line_pivot.position = glm::vec3{0, 0, 0};
  left_ = new renderer::Line();
  left_->SetStart(line_start);
  left_->SetEnd(line_end);
  left_->SetPivot(line_pivot);
  left_->material_.color = colors::WHITE;
  left_->material_.width = 2.0f;

  line_start.position = Camera::ScreenToWorld() * top_right;
  line_end.position = Camera::ScreenToWorld() * bottom_right;
  line_pivot.position = glm::vec3{0, 0, 0};
  right_ = new renderer::Line();
  right_->SetStart(line_start);
  right_->SetEnd(line_end);
  right_->SetPivot(line_pivot);
  right_->material_.color = colors::WHITE;
  right_->material_.width = 2.0f;

  line_start.position = Camera::ScreenToWorld() * top_left;
  line_end.position = Camera::ScreenToWorld() * top_right;
  line_pivot.position = glm::vec3{0, 0, 0};
  top_ = new renderer::Line();
  top_->SetStart(line_start);
  top_->SetEnd(line_end);
  top_->SetPivot(line_pivot);
  top_->material_.color = colors::WHITE;
  top_->material_.width = 2.0f;

  line_start.position = Camera::ScreenToWorld() * bottom_left;
  line_end.position = Camera::ScreenToWorld() * bottom_right;
  line_pivot.position = glm::vec3{0, 0, 0};
  bottom_ = new renderer::Line();
  bottom_->SetStart(line_start);
  bottom_->SetEnd(line_end);
  bottom_->SetPivot(line_pivot);
  bottom_->material_.color = colors::WHITE;
  bottom_->material_.width = 2.0f;
}
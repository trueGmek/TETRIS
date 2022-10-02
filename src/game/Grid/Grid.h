#ifndef TETRIS_SRC_GAME_GRID_GRID_H_
#define TETRIS_SRC_GAME_GRID_GRID_H_

#include "../GameObject.h"
#include "../../renderer/primitives/line/Line.h"
#include "GridCell.h"

template<int across, int down>
class Grid : GameObject {
 private:
  renderer::Line horizontal_lines_[down + 1]; //FROM TOP TO BOTTOM
  renderer::Line vertical_lines_[across + 1]; //FROM LEFT TO RIGHT

 public:
  Grid(glm::vec4 bottom_left, glm::vec4 bottom_right, glm::vec4 top_left, glm::vec4 top_right) {

	Transform line_pivot;
	Transform start_position;
	Transform end_position;

	start_position.position = Camera::ScreenToWorld() * top_left;
	end_position.position = Camera::ScreenToWorld() * top_right;

	glm::vec3 cell_height = Camera::ScreenToWorld() * (bottom_left - top_left);
	cell_height /= down;

	line_pivot.position = glm::vec3{0, 0, 0};
	for (int i = 0; i < down + 1; ++i) {

	  horizontal_lines_[i].SetStart(start_position);
	  horizontal_lines_[i].SetEnd(end_position);
	  horizontal_lines_[i].SetPivot(line_pivot);
	  horizontal_lines_[i].material_ = LineMaterial(colors::WHITE, 2.0f);

	  line_pivot.position += cell_height;
	}

	glm::vec3 cell_width = Camera::ScreenToWorld() * (bottom_right - bottom_left);
	cell_width /= across;

	line_pivot.position = glm::vec3{0, 0, 0};
	start_position.position = Camera::ScreenToWorld() * top_left;
	end_position.position = Camera::ScreenToWorld() * bottom_left;

	for (int i = 0; i < across + 1; ++i) {
	  vertical_lines_[i].SetStart(start_position);
	  vertical_lines_[i].SetEnd(end_position);
	  vertical_lines_[i].SetPivot(line_pivot);
	  vertical_lines_[i].material_ = LineMaterial(colors::WHITE, 2.0f);
	  line_pivot.position += cell_width;

	}
  };
  ~Grid() override = default;

  GridCell grid_cell_[across * down]{};

  void OnEnable() override {};

  void Start() override {};

  void Update() override {};

  void OnDisable() override {};

  void OnDestroy() override {};
};

#endif //TETRIS_SRC_GAME_GRID_GRID_H_

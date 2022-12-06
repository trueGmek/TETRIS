#ifndef TETRIS_SRC_GAME_GRID_BOARD_H_
#define TETRIS_SRC_GAME_GRID_BOARD_H_

#include "../../renderer/primitives/cube/Cube.h"
#include "../GameObject.h"
#include "../../renderer/primitives/Colors.h"
#include "../../renderer/primitives/line/Line.h"
#include "GridCell.h"

class Board : GameObject
{
public:
	static const int across_{ 10 };
	static const int down_{ 20 };

	GridCell cells_[across_][down_];
	Board(glm::vec3 center, glm::vec2 size);
private:
	renderer::Cube cubes_renderer_[across_ * down_];
	renderer::Line top_;
	renderer::Line bottom_;
	renderer::Line left_;
	renderer::Line right_;

	glm::vec3 center_{};
	glm::vec2 size_{};
	glm::vec3 cell_size_{};

	void OnEnable() override {
	};

	void Start() override {
	};

	void Update() override;

	void OnDisable() override {
	};

	void OnDestroy() override {
	};
	void EnableVisibleSquares(const glm::vec3& center, const glm::vec2& size);
	void InitializeSquares(const glm::vec3& center, const glm::vec2& size);
};

#endif //TETRIS_SRC_GAME_GRID_BOARD_H_

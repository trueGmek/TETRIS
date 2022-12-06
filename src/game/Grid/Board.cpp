#include "Board.h"

Board::Board(glm::vec3 center, glm::vec2 size) : center_{ center }, size_{ size } {
	cell_size_ = glm::vec3{ (float)size.x / across_, (float)size.y / down_, 1 };

	glm::vec3 left_top{ center.x - size.x / 2, center.y + size.y / 2, center.z };
	glm::vec3 right_top{ center.x + size.x / 2, center.y + size.y / 2, center.z };
	glm::vec3 left_bottom{ center.x - size.x / 2, center.y - size.y / 2, center.z };
	glm::vec3 right_bottom{ center.x + size.x / 2, center.y - size.y / 2, center.z };

	top_.start_.position = left_top;
	top_.end_.position = right_top;
	top_.material_.color = colors::WHITE;

	bottom_.start_.position = left_bottom;
	bottom_.end_.position = right_bottom;
	bottom_.material_.color = colors::WHITE;

	left_.start_.position = left_top;
	left_.end_.position = left_bottom;
	left_.material_.color = colors::WHITE;

	right_.start_.position = right_top;
	right_.end_.position = right_bottom;
	right_.material_.color = colors::WHITE;

	InitializeSquares(center, size);

}

void Board::InitializeSquares(const glm::vec3& center, const glm::vec2& size) {

	glm::vec3 left_corner{ -size.x / 2 + cell_size_.x / 2, -size.y / 2 + cell_size_.y / 2, 0 };
	for (int i = 0; i < across_; i++) {
		for (int j = 0; j < down_; j++) {
			cells_[i][j].Position = center + left_corner + glm::vec3{ i, j, 0 } * cell_size_;
		}
	}
}

void Board::EnableVisibleSquares(const glm::vec3& center, const glm::vec2& size) {

	for (int i = 0; i < across_; i++) {
		for (int j = 0; j < down_; j++) {
			int index = i * down_ + j;
			Piece* piece = cells_[i][j].Piece;

			if (piece != nullptr && piece->IsActive) {
				cubes_renderer_[index].transform_.scale = cell_size_;
				cubes_renderer_[index].transform_.position = cells_[i][j].Position;
				cubes_renderer_[index].material_.color = cells_[i][j].Color;
			}
			else {
				cubes_renderer_[index].transform_.scale = glm::vec3{ 0 };
			}
		}
	}
}

void Board::Update() {
	EnableVisibleSquares(center_, size_);
}

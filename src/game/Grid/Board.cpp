#include "Board.h"

Board::Board(glm::vec3 center, glm::vec2 size) : _center{ center }, _size{ size } {
	_cellSize = glm::vec3{ (float)size.x / ACROSS, (float)size.y / DOWN, 1 };

	glm::vec3 leftTop{ center.x - size.x / 2, center.y + size.y / 2, center.z };
	glm::vec3 rightTop{ center.x + size.x / 2, center.y + size.y / 2, center.z };
	glm::vec3 leftBottom{ center.x - size.x / 2, center.y - size.y / 2, center.z };
	glm::vec3 rightBottom{ center.x + size.x / 2, center.y - size.y / 2, center.z };

	_top.start_.position = leftTop;
	_top.end_.position = rightTop;
	_top.material_.color = colors::WHITE;

	_bottom.start_.position = leftBottom;
	_bottom.end_.position = rightBottom;
	_bottom.material_.color = colors::WHITE;

	_left.start_.position = leftTop;
	_left.end_.position = leftBottom;
	_left.material_.color = colors::WHITE;

	_right.start_.position = rightTop;
	_right.end_.position = rightBottom;
	_right.material_.color = colors::WHITE;

	InitializeSquares(center, size);
	SetUpGameState();

}

void Board::InitializeSquares(const glm::vec3& center, const glm::vec2& size) {

	glm::vec3 left_corner{ -size.x / 2 + _cellSize.x / 2, -size.y / 2 + _cellSize.y / 2, 0 };
	for (int i = 0; i < ACROSS; i++) {
		for (int j = 0; j < DOWN; j++) {
			_cells[i][j].Position = center + left_corner + glm::vec3{ i, j, 0 } * _cellSize;
		}
	}
}

void Board::EnableVisibleSquares(const glm::vec3& center, const glm::vec2& size) {

	for (int i = 0; i < ACROSS; i++) {
		for (int j = 0; j < DOWN; j++) {
			int index = i * DOWN + j;
			Piece* piece = _cells[i][j].GamePiece;

			if (piece != nullptr && piece->IsActive) {
				_cubesRenderer[index].transform_.scale = _cellSize;
				_cubesRenderer[index].transform_.position = _cells[i][j].Position;
				_cubesRenderer[index].material_.color = _cells[i][j].Color;
			}
			else {
				_cubesRenderer[index].transform_.scale = glm::vec3{ 0 };
			}
		}
	}
}

void Board::Update() {
	EnableVisibleSquares(_center, _size);
}

void Board::SetUpGameState() {
	for (int row = 0; row < ACROSS; ++row) {
		for (int column = 0; column < DOWN; ++column) {
			_cells[row][column].GamePiece = nullptr;
		}
	}
}

Piece* Board::GetPiece(glm::ivec2 position) {
	return _cells[position.x][position.y].GamePiece;
}

Piece* Board::GetPiece(int x, int y) {
	return _cells[x][y].GamePiece;
}

GridCell* Board::GetGridCell(glm::ivec2 position) {
	return &_cells[position.x][position.y];
}

GridCell* Board::GetGridCell(int x, int y) {
	return &_cells[x][y];
}

void Board::SetPiece(glm::ivec2 position, Piece* piece) {
	if (position.x >= 0 && position.x < _cells.size() && position.y >= 0 && position.y < _cells[0].size())
		_cells[position.x][position.y].GamePiece = piece;
}

void Board::SetPiece(int x, int y, Piece* piece) {
	if (x >= 0 && x < _cells.size() && y >= 0 && y < _cells[0].size())
		_cells[x][y].GamePiece = piece;
}


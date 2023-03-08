#include "Board.h"

Board::Board(glm::vec3 center, glm::vec2 size) : _center{ center }, _size{ size } {
	_cellSize = glm::vec3{ (float)size.x / GAME_ACROSS, (float)size.y / GAME_DOWN, 1 };

	glm::vec3 leftTop{ center.x - size.x / 2, center.y + size.y / 2, center.z };
	glm::vec3 rightTop{ center.x + size.x / 2, center.y + size.y / 2, center.z };
	glm::vec3 leftBottom{ center.x - size.x / 2, center.y - size.y / 2, center.z };
	glm::vec3 rightBottom{ center.x + size.x / 2, center.y - size.y / 2, center.z };

	_top.Start = leftTop;
	_top.End = rightTop;
	_top.Material.Color = Colors::WHITE;

	_bottom.Start = leftBottom;
	_bottom.End = rightBottom;
	_bottom.Material.Color = Colors::WHITE;

	_left.Start = leftTop;
	_left.End = leftBottom;
	_left.Material.Color = Colors::WHITE;

	_right.Start = rightTop;
	_right.End = rightBottom;
	_right.Material.Color = Colors::WHITE;

	InitializeSquares(center, size);
	SetUpGameState();

}

void Board::InitializeSquares(const glm::vec3& center, const glm::vec2& size) {
	glm::vec3
		leftCorner{ -size.x / 2 + _cellSize.x / 2, -size.y / 2 + _cellSize.y / 2 - VERTICAL_BUFFER * _cellSize.y, 0 };
	for (int i = 0; i < REAL_ACROSS; i++) {
		for (int j = 0; j < REAL_DOWN; j++) {
			_cells[i][j].Position = center + leftCorner + glm::vec3{ i, j, 0 } * _cellSize;
		}
	}
}

void Board::EnableVisibleSquares() {
	for (int i = 0; i < REAL_ACROSS; i++) {
		for (int j = 0; j < REAL_DOWN; j++) {
			int index = i * REAL_DOWN + j;
			Piece* piece = _cells[i][j].GamePiece;

			if (piece != nullptr) {
				_cubesRenderer[index].Scale = _cellSize;
				_cubesRenderer[index].Position = _cells[i][j].Position;
				_cubesRenderer[index].MyMaterial.Color = _cells[i][j].Color;
			}
			else {
				_cubesRenderer[index].Scale = glm::vec3{ 0 };
			}
		}
	}
}

void Board::Update() {
	EnableVisibleSquares();
}

void Board::SetUpGameState() {
	for (int row = 0; row < REAL_ACROSS; ++row) {
		for (int column = 0; column < REAL_DOWN; ++column) {
			_cells[row][column].GamePiece = nullptr;
		}
	}
}

Piece* Board::GetPiece(glm::ivec2 position) {
	if (position.x >= 0 && position.y >= 0)
		return _cells[position.x][position.y].GamePiece;

	return nullptr;
}

GridCell* Board::GetGridCell(glm::ivec2 position) {
	if (position.x >= 0 && position.y >= 0)
		return &_cells[position.x][position.y];

	return nullptr;
}

void Board::SetPiece(glm::ivec2 position, Piece* piece) {
	if (position.x >= 0 && position.x < _cells.size() && position.y >= 0 && position.y < _cells[0].size())
		_cells[position.x][position.y].GamePiece = piece;
}

void Board::SetPiece(int x, int y, Piece* piece) {
	if (x >= 0 && x < _cells.size() && y >= 0 && y < _cells[0].size())
		_cells[x][y].GamePiece = piece;
}

void Board::MoveRowsDown(int formRow) {
	for (int row = formRow; row >= 0; row--) {
		for (int column = 0; column < Board::GAME_ACROSS; ++column) {

			Piece* piece = GetPiece(glm::ivec2{ column, row });
			if (piece != nullptr && !piece->IsActive) {

				piece->Position += glm::ivec2{ 0, 1 };

				SetPiece(glm::ivec2{ column, row }, nullptr);
				SetPiece(glm::ivec2{ column, row + 1 }, piece);
			}
		}
	}
}

void Board::ClearRow(int row) {
	for (int column = 0; column < Board::REAL_ACROSS; ++column) {
		SetPiece(column, row, nullptr);
	}
}

bool Board::IsRowFull(int row) {
	for (int column = 0; column < Board::REAL_ACROSS; ++column) {
		if (GetPiece(glm::ivec2{ column, row }) == nullptr)
			return false;
	}

	return true;
}

void Board::RemovePieces(std::array<Piece*, 4>& pieces) {
	for (int i = 0; i < 4; ++i) {
		Piece* piece = pieces[i];
		SetPiece(piece->Position, nullptr);
	}

	for (int i = 0; i < 4; ++i) {
		if (pieces[i] != nullptr)
			delete pieces[i];
	}

}

Piece* Board::CreatePieces(bool isActive, glm::ivec2 coordinates) {
	auto* piece{ new Piece(isActive, coordinates) };

	SetPiece(coordinates, piece);

	return piece;
}

Board::~Board() {
	for (std::array<GridCell, 24> column : _cells) {
		for (GridCell cell : column) {
			delete cell.GamePiece;
		}
	}

}

//
// Created by gmek on 10/25/22.
//

#include <random>
#include "GameController.h"
#include "../renderer/Renderer.h"

glm::ivec2 down_dir{ 0, 1 };

std::random_device rd; // obtain a random number from hardware
std::mt19937 gen(rd()); // seed the generator
std::uniform_int_distribution<> distr(0, 6); // define the range

int piece_index = 0;

double const kMovePeriod = 0.5;
double timeSinceLastMove = 0;

GameController::GameController(Board* grid) : _current((EShape)(distr(gen)),
	_pieces[piece_index++],
	_pieces[piece_index++],
	_pieces[piece_index++],
	_pieces[piece_index++]) {

	_board = grid;
	_current.Move(glm::vec2{ 5, 5 }, *_board);
}

void GameController::Start() {
	glfwSetWindowUserPointer(renderer::window, this);

}

void GameController::Update() {
//	double current_time = glfwGetTime();
//
//	if (current_time - timeSinceLastMove >= kMovePeriod && _isUpdating) {
//		StepUpdate();
//	}

}

void GameController::StepUpdate() {

	if (_current.CanBeMoved(glm::ivec2{ 0, 1 }, *_board))
		_current.Move(glm::ivec2{ 0, 1 }, *_board);
	else
		SetNewPiece();

	ClearFullRows();

	timeSinceLastMove = glfwGetTime();
}

void GameController::SetNewPiece() {
	auto shape = (EShape)(distr(gen));
	_current = Tetromino(shape, _pieces[piece_index++], _pieces[piece_index++],
		_pieces[piece_index++], _pieces[piece_index++]);

	_current.Move(glm::vec2{ 5, 2 }, *_board);
}

void GameController::MoveTetrominoRight() {
	if (_current.CanBeMoved(glm::vec2{ 1, 0 }, *_board))
		_current.Move(glm::vec2{ 1, 0 }, *_board);
}

void GameController::MoveTetrominoLeft() {
	if (_current.CanBeMoved(glm::vec2{ -1, 0 }, *_board))
		_current.Move(glm::vec2{ -1, 0 }, *_board);
}

void GameController::DropTetromino() {
	for (int k = Board::down_; k >= 0; --k) {
		if (_current.CanBeMoved(k * down_dir, *_board)) {
			_current.Move(k * down_dir, *_board);
			return;
		}
	}
}

void GameController::ClearFullRows() {

	for (int k = 0; k < Board::down_; ++k) {

		if (IsRowFull(k)) {
			ClearRow(k);
			MoveRowsDown(k);
		}
	}
}

bool GameController::IsRowFull(int row) const {
	for (auto& cell : _board->cells_) {
		if (cell[row].Piece == nullptr)
			return false;
	}

	return true;
}

void GameController::ClearRow(int row) {
	for (auto& cell : _board->cells_) {
		cell[row].Piece = nullptr;
	}
}

void GameController::MoveRowsDown(int formRow) {

	for (int i = formRow; i >= 0; i--) {
		for (auto& row : _board->cells_) {
			if (row[i].Piece != nullptr && row[i].Piece->IsActive) {
				Piece* piece = row[i].Piece;

				row[i].Piece = nullptr;
				row[i + 1].Piece = piece;
				piece->Position += down_dir;
			}
		}
	}

}

void GameController::RotateClockwise() {
	if (_current.CanBeRotated(RotationDir::CLOCKWISE, *_board))
		_current.Rotate(RotationDir::CLOCKWISE, *_board);
}

void GameController::RotateCounterclockwise() {

	if (_current.CanBeRotated(RotationDir::COUNTERCLOCKWISE, *_board))
		_current.Rotate(RotationDir::COUNTERCLOCKWISE, *_board);
}

void GameController::DebugToggleUpdate() {
	_isUpdating = !_isUpdating;
}




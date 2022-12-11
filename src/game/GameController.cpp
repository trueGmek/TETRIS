#include <random>
#include "GameController.h"
#include "../renderer/Renderer.h"

const glm::ivec2 down_dir{ 0, 1 };

std::random_device rd; // obtain a random number from hardware
std::mt19937 gen(rd()); // seed the generator
std::uniform_int_distribution<> distr(0, 6); // define the range

double const kMovePeriod = 0.5;
double timeSinceLastMove = 0;

GameController::GameController() : _current() {

	_current = new Tetromino((EShape)(distr(gen)), _board);
	_current->Move(glm::vec2{ 5, 5 });
	glfwSetWindowUserPointer(renderer::window, this);
}

void GameController::Update() {
	double currentTime = glfwGetTime();

	if (currentTime - timeSinceLastMove >= kMovePeriod && _isUpdating) {
		StepUpdate();
	}

}

void GameController::StepUpdate() {

	if (_current->CanBeMoved(glm::ivec2{ 0, 1 }))
		_current->Move(glm::ivec2{ 0, 1 });
	else
		SetNewPiece();

	ClearFullRows();

	timeSinceLastMove = glfwGetTime();
}

void GameController::SetNewPiece() {
	auto shape = (EShape)(distr(gen));
	_current = new Tetromino(shape, _board);

	_current->Move(glm::vec2{ 5, 2 });
}

void GameController::MoveTetrominoRight() {
	if (_current->CanBeMoved(glm::vec2{ 1, 0 }))
		_current->Move(glm::vec2{ 1, 0 });
}

void GameController::MoveTetrominoLeft() {
	if (_current->CanBeMoved(glm::vec2{ -1, 0 }))
		_current->Move(glm::vec2{ -1, 0 });
}

void GameController::DropTetromino() {
	for (int k = Board::DOWN; k >= 0; --k) {
		if (_current->CanBeMoved(k * down_dir)) {
			_current->Move(k * down_dir);
			return;
		}
	}
}

void GameController::ClearFullRows() {

	for (int k = 0; k < Board::DOWN; ++k) {

		if (IsRowFull(k)) {
			ClearRow(k);
			MoveRowsDown(k);
		}
	}
}

bool GameController::IsRowFull(int row) {
	for (int column = 0; column < Board::ACROSS; ++column) {
		if (_board.GetPiece(glm::ivec2{ column, row }) == nullptr)
			return false;
	}

	return true;
}

void GameController::ClearRow(int row) {
	for (int column = 0; column < Board::ACROSS; ++column) {
		Piece* piece = _board.GetPiece(column, row);
		_board.SetPiece(column, row, nullptr);

		delete piece;
	}
}

void GameController::MoveRowsDown(int formRow) {
	for (int row = formRow; row >= 0; row--) {
		for (int column = 0; column < Board::ACROSS; ++column) {

			Piece* piece = _board.GetPiece(glm::ivec2{ column, row });
			if (piece != nullptr && piece->IsActive) {

				_board.SetPiece(glm::ivec2{ column, row }, nullptr);
				piece->Position += down_dir;
				_board.SetPiece(glm::ivec2{ column, row + 1 }, piece);
			}
		}
	}
}

void GameController::RotateClockwise() {
	if (_current->CanBeRotated(RotationDir::CLOCKWISE))
		_current->Rotate(RotationDir::CLOCKWISE);
}

void GameController::RotateCounterclockwise() {

	if (_current->CanBeRotated(RotationDir::COUNTERCLOCKWISE))
		_current->Rotate(RotationDir::COUNTERCLOCKWISE);
}

void GameController::DebugToggleUpdate() {
	_isUpdating = !_isUpdating;
}




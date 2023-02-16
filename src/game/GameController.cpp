#include <random>
#include "GameController.h"
#include "../renderer/Renderer.h"
#include "../renderer/primitives/TextPrimitive.h"

const glm::ivec2 down_dir{ 0, 1 };

int score{};

std::random_device rd; // obtain a random number from hardware
std::mt19937 gen(rd()); // seed the generator
std::uniform_int_distribution<> distr(0, 6); // define the range

Renderer::TextPrimitive* textPrimitive;

double const kMovePeriod = 0.5;
double timeSinceLastMove = 0;

GameController::GameController() : _current() {

	_current = new Tetromino((EShape)(distr(gen)), _board);
	_nextShape = (EShape)(distr(gen));

	_current->Move(glm::vec2{ 5, 2 });
	glfwSetWindowUserPointer(Renderer::window, this);

	textPrimitive = new Renderer::TextPrimitive();
	textPrimitive->MyTransform.Position = glm::vec3{ 625, 50, 0 };
	textPrimitive->MyTransform.Scale = glm::vec3{ 1.0f };
	textPrimitive->MyMaterial.color = glm::vec4{ 1.0f };

}

void GameController::Update() {
	double currentTime = glfwGetTime();

	textPrimitive->Text = std::string{ std::to_string(score) };

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
	_current = new Tetromino(_nextShape, _board);

	_nextShape = (EShape)(distr(gen));

	if (_current->CanBeMoved(glm::vec2{ 5, 2 }))
		_current->Move(glm::vec2{ 5, 2 });
	else {
		EndGame();
	}
}

void GameController::EndGame() {
	_isUpdating = false;
	for (Piece* piece : _current->Pieces) {
		_board.SetPiece(piece->Position, nullptr);
	}
	std::cout << "You lost" << std::endl;
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
	for (int i = 1; i < Board::REAL_DOWN; ++i) {
		if (_current->CanBeMoved(down_dir * i)) {
			continue;
		}
		else {
			_current->Move(down_dir * (i - 1));
			return;
		}
	}
}

void GameController::ClearFullRows() {
	for (int k = 0; k < Board::REAL_DOWN; ++k) {
		if (IsRowFull(k)) {
			ClearRow(k);
			MoveRowsDown(k);
			score++;
		}
	}
}

bool GameController::IsRowFull(int row) {
	for (int column = 0; column < Board::REAL_ACROSS; ++column) {
		if (_board.GetPiece(glm::ivec2{ column, row }) == nullptr)
			return false;
	}

	return true;
}

void GameController::ClearRow(int row) {
	for (int column = 0; column < Board::REAL_ACROSS; ++column) {
		Piece* piece = _board.GetPiece(column, row);
		_board.SetPiece(column, row, nullptr);

		delete piece;
	}
}

void GameController::MoveRowsDown(int formRow) {
	for (int row = formRow; row >= 0; row--) {
		for (int column = 0; column < Board::GAME_ACROSS; ++column) {

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




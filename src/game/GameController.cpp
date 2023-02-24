#include <random>
#include "GameController.h"
#include "../renderer/Renderer.h"
#include "PiecePreview.h"

const glm::ivec2 down_dir{ 0, 1 };

int score{};

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distr(0, 6);

double const MIN_MOVE_TIME = 0.05;
double const START_MOVE_TIME = 0.5;

double moveTime;
double timeSinceLastMove = 0;

GameController::GameController() : _current{ new Tetromino((EShape)(distr(gen)), _board) } {
	_nextShape = (EShape)(distr(gen));
	_current->Move(glm::vec2{ 5, 2 });
	glfwSetWindowUserPointer(Renderer::window, this);

	_ui.SetUpGui(_nextShape, _heldShape);
}

void GameController::Update() {
	double currentTime = glfwGetTime();

	_ui.ScoreText->Text = std::string{ std::to_string(score) };

	if (currentTime - timeSinceLastMove >= moveTime && _isUpdating) {
		StepUpdate();
	}

}

void GameController::StepUpdate() {

	if (_current->CanBeMoved(down_dir)) {
		_current->Move(down_dir);
	}
	else {
		GenerateNewPiece();
		ClearFullRows();
	}

	timeSinceLastMove = glfwGetTime();
	moveTime = CalculateMoveTime();
}

void GameController::GenerateNewPiece() {

	delete _current;
	CreateNewPiece(_nextShape);
	_nextShape = (EShape)(distr(gen));
	_ui.NextPiecePreview->SetShape(_nextShape);

	_isAbleToSwap = true;
}

void GameController::CreateNewPiece(EShape shape) {

	_current = new Tetromino(shape, _board);

	if (_current->CanBeMoved(glm::vec2{ 5, 2 })) {
		_current->Move(glm::vec2{ 5, 2 });
	}
	else {
		EndGame();
	}
}

void GameController::EndGame() {
	_isUpdating = false;

	auto pieces = _current->Pieces;
	delete _current;
	_board.RemovePieces(pieces);
	_ui.LostText->MyTransform.Scale = glm::vec3{ 2.0f };
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
	int fullRows{};

	for (int k = Board::VERTICAL_BUFFER; k < Board::REAL_DOWN; ++k) {

		if (_board.IsRowFull(k)) {

			_board.ClearRow(k);
			_board.MoveRowsDown(k);
			fullRows++;

		}
	}

	if (fullRows > 0)
		score += ScoreTable.at(fullRows);
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

void GameController::SwapPieces() {
	if (_isAbleToSwap) {
		_ui.HeldPiecePreview->SetActive(true);

		if (_isHoldingShape) {
			EShape temp = _current->Shape;

			auto pieces = _current->Pieces;
			delete _current;
			_board.RemovePieces(pieces);
			CreateNewPiece(_heldShape);

			_heldShape = temp;
			_ui.HeldPiecePreview->SetShape(_heldShape);

			_isAbleToSwap = false;
			return;
		}

		_heldShape = _current->Shape;

		auto pieces = _current->Pieces;
		delete _current;
		_board.RemovePieces(pieces);
		CreateNewPiece(_nextShape);

		_nextShape = (EShape)(distr(gen));

		_ui.HeldPiecePreview->SetShape(_heldShape);
		_ui.NextPiecePreview->SetShape(_nextShape);

		_isHoldingShape = true;
		_isAbleToSwap = false;
		return;
	}

}

double GameController::CalculateMoveTime() {
	return glm::clamp(-0.0045 * score + 0.5, MIN_MOVE_TIME, START_MOVE_TIME);
}

GameController::~GameController() {
	delete _current;
}

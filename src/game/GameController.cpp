#include <random>
#include "GameController.h"
#include "../renderer/Renderer.h"
#include "PiecePreview.h"

const glm::ivec2 down_dir{ 0, 1 };

int score{};

std::random_device rd; // obtain a random number from hardware
std::mt19937 gen(rd()); // seed the generator
std::uniform_int_distribution<> distr(0, 6); // define the range

double const MIN_MOVE_TIME = 0.05;
double const START_MOVE_TIME = 0.5;

double moveTime;
double timeSinceLastMove = 0;

GameController::GameController() : _current() {

	_current = new Tetromino((EShape)(distr(gen)), _board);
	_nextShape = (EShape)(distr(gen));

	_current->Move(glm::vec2{ 5, 2 });
	glfwSetWindowUserPointer(Renderer::window, this);

	ui = new GameUI();
	ui->SetUpGui(_nextShape, _heldShape);
}

void GameController::Update() {
	double currentTime = glfwGetTime();

	ui->ScoreText->Text = std::string{ std::to_string(score) };

	if (currentTime - timeSinceLastMove >= moveTime && _isUpdating) {
		StepUpdate();

		moveTime = CalculateMoveTime();
		std::cout << moveTime << std::endl;
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
}

void GameController::GenerateNewPiece() {
	CreateNewPiece(_nextShape);
	_nextShape = (EShape)(distr(gen));
	ui->NextPiecePreview->SetShape(_nextShape);

	_isAbleToSwap = true;
}

void GameController::CreateNewPiece(EShape shape) {

	delete _current;
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

	_board.RemovePieces(_current->Pieces);
	delete _current;

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
		ui->HeldPiecePreview->SetActive(true);

		if (_isHoldingShape) {
			EShape temp = _current->Shape;

			_board.RemovePieces(_current->Pieces);
			CreateNewPiece(_heldShape);

			_heldShape = temp;
			ui->HeldPiecePreview->SetShape(_heldShape);

			_isAbleToSwap = false;
			return;
		}

		_heldShape = _current->Shape;

		_board.RemovePieces(_current->Pieces);
		CreateNewPiece(_nextShape);

		_nextShape = (EShape)(distr(gen));

		ui->HeldPiecePreview->SetShape(_heldShape);
		ui->NextPiecePreview->SetShape(_nextShape);

		_isHoldingShape = true;
		_isAbleToSwap = false;
		return;
	}

}

double GameController::CalculateMoveTime() {
	return glm::clamp(-0.0045 * score + 0.5, MIN_MOVE_TIME, START_MOVE_TIME);
}

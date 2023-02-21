#include <random>
#include "GameController.h"
#include "../renderer/Renderer.h"
#include "PiecePreview.h"

const glm::ivec2 down_dir{ 0, 1 };

int score{};

std::random_device rd; // obtain a random number from hardware
std::mt19937 gen(rd()); // seed the generator
std::uniform_int_distribution<> distr(0, 6); // define the range

double const kMovePeriod = 0.5;
double timeSinceLastMove = 0;

GameController::GameController() : _current() {

	_current = new Tetromino((EShape)(distr(gen)), _board);
	_nextShape = (EShape)(distr(gen));

	_current->Move(glm::vec2{ 5, 2 });
	glfwSetWindowUserPointer(Renderer::window, this);

	SetUpGUI();
}

void GameController::SetUpGUI() {
	_nextPiecePreview = new PiecePreview(glm::vec3{ 40, 40, 1 });
	_nextPiecePreview->MyTransform.Position = glm::vec3{ 725, 165, 0 };
	_nextPiecePreview->SetShape(_nextShape);

	_heldPiecePreview = new PiecePreview(glm::vec3{ 40, 40, 1 });
	_heldPiecePreview->MyTransform.Position = glm::vec3{ 725, 375, 0 };
	_heldPiecePreview->SetShape(_heldShape);
	_heldPiecePreview->SetActive(false);

	_scoreText = new Renderer::TextPrimitive();
	_scoreText->MyTransform.Position = glm::vec3{ 75, 100, 0 };
	_scoreText->MyTransform.Scale = glm::vec3{ 1.0f };
	_scoreText->MyMaterial.color = glm::vec4{ 1.0f };

	_nextPieceTitle = new Renderer::TextPrimitive();
	_nextPieceTitle->MyTransform.Position = glm::vec3{ 625, 75, 0 };
	_nextPieceTitle->MyTransform.Scale = glm::vec3{ 0.5f };
	_nextPieceTitle->MyMaterial.color = glm::vec4{ 1.0f };
	_nextPieceTitle->Text = "NEXT PIECE";

	_heldPieceTitle = new Renderer::TextPrimitive();
	_heldPieceTitle->MyTransform.Position = glm::vec3{ 625, 300, 0 };
	_heldPieceTitle->MyTransform.Scale = glm::vec3{ 0.5f };
	_heldPieceTitle->MyMaterial.color = glm::vec4{ 1.0f };
	_heldPieceTitle->Text = "HELD PIECE";

	_scoreTitle = new Renderer::TextPrimitive();
	_scoreTitle->MyTransform.Position = glm::vec3{ 50, 50, 0 };
	_scoreTitle->MyTransform.Scale = glm::vec3{ .5f };
	_scoreTitle->MyMaterial.color = glm::vec4{ 1.0f };
	_scoreTitle->Text = "SCORE";
}

void GameController::Update() {
	double currentTime = glfwGetTime();

	_scoreText->Text = std::string{ std::to_string(score) };

	if (currentTime - timeSinceLastMove >= kMovePeriod && _isUpdating) {
		StepUpdate();
	}

}

void GameController::StepUpdate() {

	if (_current->CanBeMoved(glm::ivec2{ 0, 1 }))
		_current->Move(glm::ivec2{ 0, 1 });
	else
		GenerateNewPiece();

	ClearFullRows();

	timeSinceLastMove = glfwGetTime();
}

void GameController::GenerateNewPiece() {
	SetNewPiece(_nextShape);
	_nextShape = (EShape)(distr(gen));
	_nextPiecePreview->SetShape(_nextShape);

	_isAbleToSwap = true;
}

void GameController::SetNewPiece(EShape shape) {
	_current->SetShape(shape);

	if (_current->CanBeMoved(glm::vec2{ 5, 2 })) {
		_current->Move(glm::vec2{ 5, 2 });
	}
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

void GameController::SwapPieces() {
	if (_isAbleToSwap) {
		_heldPiecePreview->SetActive(true);

		if (_isHoldingShape) {
			EShape temp = _current->Shape;

			_current->Clear();
			SetNewPiece(_heldShape);

			_heldShape = temp;
			_heldPiecePreview->SetShape(_heldShape);

			_isAbleToSwap = false;
			return;
		}

		_heldShape = _current->Shape;

		_current->Clear();
		SetNewPiece(_nextShape);

		_nextShape = (EShape)(distr(gen));

		_heldPiecePreview->SetShape(_heldShape);
		_nextPiecePreview->SetShape(_nextShape);

		_isHoldingShape = true;
		_isAbleToSwap = false;

		return;
	}

}





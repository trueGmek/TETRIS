//
// Created by gmek on 11/1/22.
//

#include "Tetromino.h"
#include "../../utils/MathUtil.h"
#include "TetrominoData.h"

Tetromino::Tetromino(EShape shape, Board& board)
	: Pieces{}, GameBoard(board), Shape{ shape } {
	std::array<glm::ivec2, 4> shapeCoordinates = TetrominoData[shape].Coordinates;

	for (int i = 0; i < 4; ++i) {
		Pieces[i] = new Piece();
		Pieces[i]->IsActive = true;
		Pieces[i]->Position = shapeCoordinates[i];
	}

	for (Piece* tetrominoPart : Pieces) {
		GameBoard.SetPiece(tetrominoPart->Position, tetrominoPart);
	}
}

bool Tetromino::CanBeMoved(glm::ivec2 direction) {

	bool isAllowed = true;

	for (Piece* tetrominoPart : Pieces) {

		if (tetrominoPart->Position.x + direction.x >= Board::REAL_ACROSS
			|| tetrominoPart->Position.y + direction.y >= Board::REAL_DOWN)
			return false;

		if (tetrominoPart->Position.x + direction.x < 0)
			return false;

		bool isPieceAtDestination = GameBoard.GetPiece(tetrominoPart->Position + direction) != nullptr;

		if (isPieceAtDestination)
			isAllowed &= IsPiecePartOfTetromino(tetrominoPart->Position + direction);
	}

	return isAllowed;
}

bool Tetromino::IsPiecePartOfTetromino(glm::ivec2 destination) {
	for (Piece* piece : Pieces) {
		if (destination == piece->Position)
			return true;
	}
	return false;
}

void Tetromino::Move(glm::ivec2 direction) {

	for (Piece* tetrominoPart : Pieces) {
		GameBoard.SetPiece(tetrominoPart->Position, nullptr);
	}

	for (Piece* tetrominoPart : Pieces) {
		tetrominoPart->Position += direction;
	}

	for (Piece* tetrominoPart : Pieces) {
		GameBoard.SetPiece(tetrominoPart->Position, tetrominoPart);
	}

	SetColors();
}

void Tetromino::SetColors() {
	for (auto tetrominoPart : Pieces) {
		GameBoard.GetGridCell(tetrominoPart->Position)->Color = TetrominoData[Shape].Color;
	}
}

bool Tetromino::CanBeRotated(RotationDir direction) {

	bool isAllowed = true;

	glm::ivec2 anchorPosition = Pieces[0]->Position;
	for (Piece* tetrominoPart : Pieces) {

		glm::ivec2 relativePosition = tetrominoPart->Position - anchorPosition;
		glm::mat2 rotationMatrix = GetRotationMatrix(direction == CLOCKWISE ? 90 : 270);
		glm::vec2 newFloatPosition = rotationMatrix * relativePosition;
		glm::ivec2 newRelativePosition = glm::round(newFloatPosition);
		glm::ivec2 newPosition = newRelativePosition + anchorPosition;

		if (newPosition.x >= Board::REAL_ACROSS || newPosition.y >= Board::REAL_DOWN || newPosition.x < 0
			|| newPosition.y < 0)
			return false;

		if (GameBoard.GetPiece(newPosition) != nullptr)
			isAllowed &= IsPiecePartOfTetromino(newPosition);

	}

	return isAllowed;
}

void Tetromino::Rotate(RotationDir direction) {
	for (Piece* tetrominoPart : Pieces) {
		GameBoard.SetPiece(tetrominoPart->Position, nullptr);
	}

	glm::ivec2 anchorPosition = Pieces[0]->Position;
	for (Piece* tetrominoPart : Pieces) {
		glm::ivec2 relativePosition = tetrominoPart->Position - anchorPosition;
		glm::mat2 rotationMatrix = GetRotationMatrix(direction == CLOCKWISE ? 90 : 270);

		glm::vec2 newFloatPosition = rotationMatrix * relativePosition;
		glm::ivec2 newRelativePosition = glm::round(newFloatPosition);
		tetrominoPart->Position = newRelativePosition + anchorPosition;
	}

	for (Piece* tetrominoPart : Pieces) {
		GameBoard.SetPiece(tetrominoPart->Position, tetrominoPart);
	}

	SetColors();

}

Tetromino::~Tetromino() {
	for (Piece* tetrominoPart : Pieces) {
		tetrominoPart->IsActive = false;
	}
}

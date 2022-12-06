//
// Created by gmek on 11/1/22.
//

#include "Tetromino.h"
#include "../../utils/MathUtil.h"
#include "TetrominoData.h"

glm::vec4 debugColors[] = { colors::RED, colors::GREEN, colors::BLUE, colors::WHITE };

Tetromino::Tetromino(EShape shape, Piece& piece1, Piece& piece2, Piece& piece3, Piece& piece4) : Pieces{ piece1,
																										 piece2,
																										 piece3,
																										 piece4 } {
	std::array<glm::ivec2, 4> shapeCoordinates = TetrominoData[shape].Coordinates;

	for (int i = 0; i < 4; ++i) {
		Pieces[i].IsActive = true;
		Pieces[i].Position = shapeCoordinates[i];
	}

}

bool Tetromino::CanBeMoved(glm::ivec2 direction, Board& board) {

	bool isAllowed = true;

	for (Piece tetrominoPart : Pieces) {

		if (tetrominoPart.Position.x + direction.x >= Board::across_
			|| tetrominoPart.Position.y + direction.y >= Board::down_)
			return false;

		if (tetrominoPart.Position.x + direction.x < 0 || tetrominoPart.Position.y + direction.y < 0)
			return false;

		GridCell cellAtDestination =
			board.cells_[tetrominoPart.Position.x + direction.x][tetrominoPart.Position.y + direction.y];

		if (cellAtDestination.Piece == nullptr)
			continue; // its empty, nothing to worry about;

		isAllowed &= IsPiecePartOfTetromino(tetrominoPart.Position + direction);
	}

	return isAllowed;

}

bool Tetromino::IsPiecePartOfTetromino(glm::ivec2 destination) {

	for (Piece piece : Pieces) {
		if (destination == piece.Position)
			return true;
	}
	return false;
}

void Tetromino::Move(glm::ivec2 direction, Board& board) {

	for (Piece tetrominoPart : Pieces) {
		board.cells_[tetrominoPart.Position.x][tetrominoPart.Position.y].Piece = nullptr;
	}

	for (Piece tetrominoPart : Pieces) {
		tetrominoPart.Position += direction;
	}

	for (Piece tetrominoPart : Pieces) {
		board.cells_[tetrominoPart.Position.x][tetrominoPart.Position.y].Piece = &tetrominoPart;
	}

	SetColors(board);
}

void Tetromino::SetColors(Board& board) {
	for (int i = 0; i < 4; ++i) {
		Piece tetrominoPart = Pieces[i];
		board.cells_[tetrominoPart.Position.x][tetrominoPart.Position.y].color = debugColors[i];
	}
}

bool Tetromino::CanBeRotated(RotationDir direction, Board& board) {

	bool isAllowed = true;

	glm::ivec2 anchorPosition = Pieces[0].Position;
	for (Piece tetrominoPart : Pieces) {

		glm::ivec2 relativePosition = tetrominoPart.Position - anchorPosition;
		glm::mat2 rotationMatrix = GetRotationMatrix(direction == CLOCKWISE ? 90 : 270);
		glm::vec2 newFloatPosition = rotationMatrix * relativePosition;
		glm::ivec2 newRelativePosition = glm::round(newFloatPosition);
		glm::ivec2 newPosition = newRelativePosition + anchorPosition;

		if (newPosition.x >= Board::across_ || newPosition.y >= Board::down_ || newPosition.x < 0
			|| newPosition.y < 0)
			return false;

		GridCell cell_at_destination = board.cells_[newPosition.x][newPosition.y];

		if (cell_at_destination.Piece == nullptr)
			continue; // its empty, nothing to worry about;

		isAllowed &= IsPiecePartOfTetromino(newPosition);

	}

	return isAllowed;
}

void Tetromino::Rotate(RotationDir direction, Board& board) {
	for (Piece tetrominoPart : Pieces) {
		board.cells_[tetrominoPart.Position.x][tetrominoPart.Position.y].Piece = nullptr;
	}

	glm::ivec2 anchorPosition = Pieces[0].Position;
	for (Piece tetrominoPart : Pieces) {
		glm::ivec2 relativePosition = tetrominoPart.Position - anchorPosition;
		glm::mat2 rotationMatrix = GetRotationMatrix(direction == CLOCKWISE ? 90 : 270);

		glm::vec2 newFloatPosition = rotationMatrix * relativePosition;
		glm::ivec2 newRelativePosition = glm::round(newFloatPosition);
		tetrominoPart.Position = newRelativePosition + anchorPosition;
	}

	for (Piece tetrominoPart : Pieces) {
		board.cells_[tetrominoPart.Position.x][tetrominoPart.Position.y].Piece = &tetrominoPart;
	}

	SetColors(board);

}

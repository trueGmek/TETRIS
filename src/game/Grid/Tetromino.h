#pragma once

#include "glm/ext/vector_int2.hpp"
#include "Board.h"
#include "TetrominoData.h"

enum RotationDir
{
	CLOCKWISE,
	COUNTERCLOCKWISE,
};

class Tetromino
{
public:
	std::array<Piece*, 4> Pieces;
	Board& GameBoard;
	EShape Shape;

	explicit Tetromino(EShape shape, Board& board);
	~Tetromino();
	bool CanBeMoved(glm::ivec2 direction);
	void Move(glm::ivec2 direction);

	bool CanBeRotated(RotationDir direction);
	void Rotate(RotationDir direction);
	bool IsPiecePartOfTetromino(glm::ivec2 destination);

	static glm::mat2 GetRotationMatrix(float rotationAngle);

	void SetColors();
};

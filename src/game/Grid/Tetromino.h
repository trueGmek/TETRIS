#ifndef TETRIS_SRC_GAME_GRID_TETROMINO_H
#define TETRIS_SRC_GAME_GRID_TETROMINO_H

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
	Piece* Pieces[4];
	Board& GameBoard;
	EShape Shape;

	explicit Tetromino(EShape shape, Board& board);
	~Tetromino();

	bool CanBeMoved(glm::ivec2 direction);
	void Move(glm::ivec2 direction);

	bool CanBeRotated(RotationDir direction);
	void Rotate(RotationDir direction);
	bool IsPiecePartOfTetromino(glm::ivec2 destination);

	void SetColors();
};

#endif //TETRIS_SRC_GAME_GRID_TETROMINO_H

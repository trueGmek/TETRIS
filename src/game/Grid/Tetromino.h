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
	Piece Pieces[4];

	explicit Tetromino(EShape shape, Piece& piece1, Piece& piece2, Piece& piece3, Piece& piece4);

	bool CanBeMoved(glm::ivec2 direction, Board& board);
	void Move(glm::ivec2 direction, Board& board);

	bool CanBeRotated(RotationDir direction, Board& board);
	void Rotate(RotationDir direction, Board& board);
	bool IsPiecePartOfTetromino(glm::ivec2 destination);

	void SetColors(Board& board);
};

#endif //TETRIS_SRC_GAME_GRID_TETROMINO_H

#ifndef TETRIS_SRC_GAME_GRID_PIECE_H
#define TETRIS_SRC_GAME_GRID_PIECE_H

#include "glm/vec2.hpp"

class Piece
{
public:
	bool IsActive = false;
	glm::ivec2 Position = { 0, 0 };

public:
	Piece();
	Piece(bool isActive, const glm::ivec2& position);
};

#endif //TETRIS_SRC_GAME_GRID_PIECE_H

#ifndef TETRIS_SRC_GAME_GRID_PIECE_H
#define TETRIS_SRC_GAME_GRID_PIECE_H

#include "glm/vec2.hpp"

class Piece
{
public:
	bool IsActive = false;
	glm::ivec2 Position = { 0, 0 };
};

#endif //TETRIS_SRC_GAME_GRID_PIECE_H

//
// Created by gmek on 11/1/22.
//

#ifndef tetris_src_game_grid_piece_h_
#define tetris_src_game_grid_piece_h_

#include "glm/vec2.hpp"
#include "Board.h"

class Board;

class Piece
{
public:
	bool IsActive = false;
	glm::ivec2 Position = { 0, 0 };
};

#endif //TETRIS_SRC_GAME_GRID_PIECE_H_

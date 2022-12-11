#ifndef TETRIS_SRC_GAME_GRID_GRIDCELL_H_
#define TETRIS_SRC_GAME_GRID_GRIDCELL_H_

#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "Piece.h"

class Piece;

struct GridCell
{
	glm::vec4 Color;
	glm::vec3 Position;
	Piece* GamePiece;
};

#endif //TETRIS_SRC_GAME_GRID_GRIDCELL_H_

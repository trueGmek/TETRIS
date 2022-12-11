#ifndef TETRIS_SRC_GAME_GRID_TETROMINODATA_H
#define TETRIS_SRC_GAME_GRID_TETROMINODATA_H

#include <array>
#include <map>
#include "glm/ext/vector_int2.hpp"
#include "Tetromino.h"

enum EShape
{
	I = 0,
	O = 1,
	T = 2,
	S = 3,
	Z = 4,
	J = 5,
	L = 6,
};

struct data
{
	std::array<glm::ivec2, 4> Coordinates;
	glm::vec4 Color;
};

static std::map<EShape, data> TetrominoData{
	{ EShape::I, {{
					  glm::ivec2{ 0, 0 },
					  glm::ivec2{ 0, -1 },
					  glm::ivec2{ 0, 1 },
					  glm::ivec2{ 0, 2 }
				  }, { colors::LIGHT_BLUE }}},
	{ EShape::O, {{
					  glm::ivec2{ 0, 0 },
					  glm::ivec2{ -1, 0 },
					  glm::ivec2{ -1, 1 },
					  glm::ivec2{ 0, 1 }
				  }, { colors::YELLOW }}},
	{ EShape::T, {{
					  glm::ivec2{ 0, 0 },
					  glm::ivec2{ -1, 0 },
					  glm::ivec2{ 1, 0 },
					  glm::ivec2{ 0, -1 }
				  }, { colors::PURPLE }}},
	{ EShape::S, {{
					  glm::ivec2{ 0, 0 },
					  glm::ivec2{ 1, 0 },
					  glm::ivec2{ -1, 1 },
					  glm::ivec2{ 0, 1 },
				  }, { colors::GREEN }}},
	{ EShape::Z, {{
					  glm::ivec2{ 0, 0 },
					  glm::ivec2{ -1, 0 },
					  glm::ivec2{ 0, 1 },
					  glm::ivec2{ 1, 1 },
				  }, { colors::RED }}},
	{ EShape::J, {{
					  glm::ivec2{ 0, 0 },
					  glm::ivec2{ 1, 0 },
					  glm::ivec2{ -1, 0 },
					  glm::ivec2{ -1, -1 },
				  }, { colors::BLUE }}},
	{ EShape::L, {{
					  glm::ivec2{ 0, 0 },
					  glm::ivec2{ 1, -1 },
					  glm::ivec2{ -1, 0 },
					  glm::ivec2{ 1, 0 }
				  }, { colors::ORANGE }}},

};

#endif //TETRIS_SRC_GAME_GRID_TETROMINODATA_H

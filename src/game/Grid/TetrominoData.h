#ifndef TETRIS_SRC_GAME_GRID_TETROMINODATA_H
#define TETRIS_SRC_GAME_GRID_TETROMINODATA_H

#include <array>
#include <map>
#include "glm/ext/vector_int2.hpp"
#include "../../renderer/primitives/Colors.h"

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
				  }, { Colors::LIGHT_BLUE }}},
	{ EShape::O, {{
					  glm::ivec2{ 0, 0 },
					  glm::ivec2{ -1, 0 },
					  glm::ivec2{ -1, 1 },
					  glm::ivec2{ 0, 1 }
				  }, { Colors::YELLOW }}},
	{ EShape::T, {{
					  glm::ivec2{ 0, 0 },
					  glm::ivec2{ -1, 0 },
					  glm::ivec2{ 1, 0 },
					  glm::ivec2{ 0, -1 }
				  }, { Colors::PURPLE }}},
	{ EShape::S, {{
					  glm::ivec2{ 0, 0 },
					  glm::ivec2{ 1, 0 },
					  glm::ivec2{ -1, 1 },
					  glm::ivec2{ 0, 1 },
				  }, { Colors::GREEN }}},
	{ EShape::Z, {{
					  glm::ivec2{ 0, 0 },
					  glm::ivec2{ -1, 0 },
					  glm::ivec2{ 0, 1 },
					  glm::ivec2{ 1, 1 },
				  }, { Colors::RED }}},
	{ EShape::J, {{
					  glm::ivec2{ 0, 0 },
					  glm::ivec2{ 1, 0 },
					  glm::ivec2{ -1, 0 },
					  glm::ivec2{ -1, -1 },
				  }, { Colors::BLUE }}},
	{ EShape::L, {{
					  glm::ivec2{ 0, 0 },
					  glm::ivec2{ 1, -1 },
					  glm::ivec2{ -1, 0 },
					  glm::ivec2{ 1, 0 }
				  }, { Colors::ORANGE }}},

};

#endif //TETRIS_SRC_GAME_GRID_TETROMINODATA_H

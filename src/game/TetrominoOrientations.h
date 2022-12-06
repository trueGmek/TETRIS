//
// Created by gmek on 11/8/22.
//

#ifndef TETRIS_SRC_GAME_TETROMINOORIENTATIONS_H_
#define TETRIS_SRC_GAME_TETROMINOORIENTATIONS_H_

#include <map>
#include <vector>
#include "Grid/Tetromino.h"

struct orientation
{
	glm::ivec2 positions[4];

	orientation(const glm::ivec2 p_0, const glm::ivec2 p_1, const glm::ivec2 p_2, const glm::ivec2 p_3) : positions{
		p_0,
		p_1,
		p_2,
		p_3 } {
	}

	orientation() : positions{ glm::zero<glm::ivec2>(), glm::zero<glm::ivec2>(), glm::zero<glm::ivec2>(),
							   glm::zero<glm::ivec2>(), } {
	}
};

struct TetrominoWithRotations
{
	orientation orientations[4];

	TetrominoWithRotations(const orientation o_0, const orientation o_1, const orientation o_2, const orientation o_3)
		: orientations{ o_0, o_1, o_2, o_3 } {
	}
};

const std::map<EShape, TetrominoWithRotations> orientations{
	{ I,
	  {{{ 0, 1 }, { 1, 1 }, { 2, 1 }, { 3, 1 }},
	   {{ 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 }},
	   {{ 0, 1 }, { 1, 1 }, { 2, 1 }, { 3, 1 }},
	   {{ 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 }}}
	},
	{ O, {{{ 1, 1 }, { 2, 1 }, { 1, 2 }, { 2, 2 }},
		  {{ 1, 1 }, { 2, 1 }, { 1, 2 }, { 2, 2 }},
		  {{ 1, 1 }, { 2, 1 }, { 1, 2 }, { 2, 2 }},
		  {{ 1, 1 }, { 2, 1 }, { 1, 2 }, { 2, 2 }}}
	},
	{ S, {{{ 1, 1 }, { 2, 1 }, { 0, 3 }, { 1, 3 }},
		  {{ 1, 0 }, { 1, 1 }, { 2, 1 }, { 2, 2 }},
		  {{ 1, 1 }, { 2, 1 }, { 0, 3 }, { 1, 3 }},
		  {{ 1, 0 }, { 1, 1 }, { 2, 1 }, { 2, 2 }}}
	},
	{ T, {{{ 0, 1 }, { 1, 1 }, { 2, 1 }, { 1, 2 }},
		  {{ 1, 0 }, { 1, 1 }, { 2, 1 }, { 1, 2 }},
		  {{ 1, 0 }, { 0, 1 }, { 1, 1 }, { 2, 1 }},
		  {{ 1, 0 }, { 0, 1 }, { 1, 1 }, { 1, 2 }}}
	},

	{ Z, {{{ 0, 1 }, { 1, 1 }, { 1, 2 }, { 2, 2 }},
		  {{ 2, 0 }, { 1, 1 }, { 2, 1 }, { 1, 2 }},
		  {{ 0, 1 }, { 1, 1 }, { 1, 2 }, { 2, 2 }},
		  {{ 2, 0 }, { 1, 1 }, { 2, 1 }, { 1, 2 }}}
	},

	{ J, {{{ 0, 1 }, { 1, 1 }, { 2, 1 }, { 2, 2 }},
		  {{ 1, 0 }, { 2, 0 }, { 1, 1 }, { 1, 2 }},
		  {{ 0, 0 }, { 0, 1 }, { 1, 1 }, { 2, 1 }},
		  {{ 1, 0 }, { 1, 1 }, { 1, 2 }, { 0, 2 }}}
	},

	{ L, {{{ 0, 1 }, { 1, 1 }, { 2, 1 }, { 0, 2 }},
		  {{ 1, 0 }, { 1, 1 }, { 1, 2 }, { 2, 2 }},
		  {{ 0, 1 }, { 1, 1 }, { 2, 1 }, { 2, 0 }},
		  {{ 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 2 }}}
	},
};

#endif //TETRIS_SRC_GAME_TETROMINOORIENTATIONS_H_

#pragma once

#include <map>
#include <vector>
#include "Grid/Tetromino.h"

struct orientation
{
	glm::ivec2 positions[4];

	orientation(const glm::ivec2 p0, const glm::ivec2 p1, const glm::ivec2 p2, const glm::ivec2 p3) : positions{
		p0,
		p1,
		p2,
		p3 } {
	}

	orientation() : positions{ glm::zero<glm::ivec2>(), glm::zero<glm::ivec2>(), glm::zero<glm::ivec2>(),
							   glm::zero<glm::ivec2>(), } {
	}
};

struct TetrominoWithRotations
{
	orientation orientations[4];

	TetrominoWithRotations(const orientation o0, const orientation o1, const orientation o2, const orientation o3)
		: orientations{ o0, o1, o2, o3 } {
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

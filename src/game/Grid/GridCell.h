#pragma once

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

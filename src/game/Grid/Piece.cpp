//
// Created by gmek on 11/1/22.
//

#include "Piece.h"

Piece::Piece(bool isActive, const glm::ivec2& position) : IsActive(isActive), Position(position) {
}

Piece::Piece() = default;

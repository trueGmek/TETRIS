#include "Piece.h"

Piece::Piece(bool isActive, const glm::ivec2& position) : IsActive(isActive), Position(position) {
}

Piece::Piece() = default;

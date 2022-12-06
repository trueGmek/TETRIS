#ifndef TETRIS_SRC_UTILS_MATHUTIL_H
#define TETRIS_SRC_UTILS_MATHUTIL_H

#include "glm/mat2x2.hpp"
#include "glm/trigonometric.hpp"

glm::mat2 static GetRotationMatrix(float rotationAngle) {
	float angle = glm::radians(rotationAngle);
	return glm::mat2x2{{ glm::cos(angle), glm::sin(angle) }, { -glm::sin(angle), glm::cos(angle) }};
}

#endif //TETRIS_SRC_UTILS_MATHUTIL_H

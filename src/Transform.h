#ifndef TETRIS_SRC_TRANSFORM_H_
#define TETRIS_SRC_TRANSFORM_H_

#include "glm/vec3.hpp"
#include "glm/gtc/quaternion.hpp"

struct Transform
{
	glm::vec3 position{ 0.0f, 0.0f, 0.0f };
	glm::quat rotation{ 1.0f, 0.0f, 0.0f, 0.0f };
	glm::vec3 scale{ 1, 1, 1 };
};

#endif //TETRIS_SRC_TRANSFORM_H_

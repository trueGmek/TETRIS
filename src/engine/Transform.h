#pragma once

#include "glm/vec3.hpp"
#include "glm/gtc/quaternion.hpp"

struct Transform
{
	glm::vec3 Position{ 0.0f, 0.0f, 0.0f };
	glm::quat Rotation{ 1.0f, 0.0f, 0.0f, 0.0f };
	glm::vec3 Scale{ 1, 1, 1 };
};

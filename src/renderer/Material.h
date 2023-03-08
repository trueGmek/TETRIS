#pragma once

#include "glm/vec4.hpp"

struct Material
{
	glm::vec4 Color{ 0 };
	explicit Material() = default;

	explicit Material(const glm::vec4& color) : Color(color) {
	}
};

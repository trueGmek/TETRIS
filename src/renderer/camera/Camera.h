#pragma once

#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/mat4x4.hpp"

class Camera
{
public:
	static glm::mat4 GetProjectionMatrix();
	static glm::mat4 GetViewMatrix();
};

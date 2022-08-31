#include "Camera.h"

Camera::Camera() = default;

glm::mat4 Camera::GetProjectionMatrix()
{
	return glm::ortho(-2.0f, +2.0f, -1.5f, +1.5f, 0.1f, 100.0f);
}

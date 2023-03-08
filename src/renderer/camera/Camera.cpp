#include "Camera.h"
#include "Renderer.h"

glm::mat4 Camera::GetProjectionMatrix() {
	return glm::ortho(0.0f, Renderer::windowWidth, Renderer::windowHeight, 0.0f, 0.1f, 100.0f);
}

glm::mat4 Camera::GetViewMatrix() {
	glm::mat4 view{ 1.0f };
	glm::vec3 cameraPositionInWorld{ 0, 0, -1 };
	view = glm::translate(view, cameraPositionInWorld);

	return view;
}
#include "Camera.h"
#include "../renderer/Renderer.h"

glm::mat4 Camera::ProjectionMatrix() {
	return glm::ortho(0.0f, Renderer::windowWidth, Renderer::windowHeight, 0.0f, 0.1f, 100.0f);
}

glm::mat4 Camera::ViewMatrix() {
	glm::mat4 view{ 1.0f };
	glm::vec3 cameraPositionInWorld{0,0,-1};
	view = glm::translate(view, cameraPositionInWorld);

	return view;
}

glm::mat4 Camera::ScreenToWorld() {
	return glm::inverse(ProjectionMatrix() * ViewMatrix());
}

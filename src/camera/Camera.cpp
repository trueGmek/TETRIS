#include "Camera.h"

Camera::Camera() = default;

glm::mat4 Camera::ProjectionMatrix() {
  return glm::ortho(-8.0f, +8.0f, -8.0f, +8.0f, 0.1f, 100.0f);
}

glm::mat4 Camera::ViewMatrix() {
  glm::mat4 view{1.0f};
  view = glm::translate(view, glm::vec3(0, 0, -1));

  return view;
}

glm::mat4 Camera::ScreenToWorld() {
  return glm::inverse(ProjectionMatrix() * ViewMatrix());
}

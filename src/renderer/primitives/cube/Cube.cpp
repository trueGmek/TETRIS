#include "Cube.h"

const std::string kVertexShaderPath = "/home/gmek/Dev/C++/OpenGL/tetris/resources/shaders/cube/cube.vert";
const std::string kFragmentShaderPath = "/home/gmek/Dev/C++/OpenGL/tetris/resources/shaders/cube/cube.frag";

float const kVertices[] = {
	-0.5f, 0.5, 0,    //TOP LEFT
	0.5f, 0.5f, 0,   // TOP RIGHT
	-0.5f, -0.5f, 0, // BOTTOM LEFT
	0.5f, -0.5f, 0 //BOTTOM RIGHT
};

unsigned int const kIndices[] = {
	0, 2, 3,
	0, 1, 3
};

namespace renderer {
Cube::Cube() {
  shader_ = new Shader(kVertexShaderPath, kFragmentShaderPath);

  glGenVertexArrays(1, &vao_);
  glGenBuffers(1, &vbo_);
  glGenBuffers(1, &ebo_);

  glBindVertexArray(vao_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(kIndices), kIndices, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(kVertices), kVertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
  glEnableVertexAttribArray(0);

}

Cube::~Cube() {
  glDeleteVertexArrays(1, &vao_);
  glDeleteBuffers(1, &vbo_);
  glDeleteBuffers(1, &ebo_);

  delete shader_;
}

void Cube::SetTransform(const Transform &transform) {
  transform_ = transform;
}

void Cube::Draw() {
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

void Cube::SetData() {
  glm::mat4 model{1.0f};
  model = glm::translate(model, transform_.position);
  model = glm::rotate(model, angle(transform_.rotation), axis(transform_.rotation));
  model = glm::scale(model, transform_.scale);
  glm::mat4 mvp = Camera::ProjectionMatrix() * Camera::ViewMatrix() * model;

  shader_->SetMat4Uniform("MVP", mvp);
  shader_->SetVec4Uniform("Color", material_.color);
}

void Cube::Bind() {
  glBindVertexArray(vao_);
  shader_->Use();
}

void Cube::Unbind() {
  glBindVertexArray(0);
}
} // Renderer
#include "Line.h"
#include "../../../camera/Camera.h"
#include "../../Provider.h"

const std::string kVertexShaderPath = "/home/gmek/Dev/C++/OpenGL/tetris/resources/shaders/line/line.vert";
const std::string kFragmentShaderPath = "/home/gmek/Dev/C++/OpenGL/tetris/resources/shaders/line/line.frag";

namespace renderer {

Line::Line() {
  shader_ = new Shader(kVertexShaderPath, kFragmentShaderPath);
  glGenVertexArrays(1, &vao_);
  glGenBuffers(1, &vbo_);
  renderer::primitives.insert(primitives.end(), this);
}

Line::Line(Transform start, Transform end, Transform pivot, LineMaterial line_material)
	: pivot_(pivot), start_(start), end_(end), material_(line_material) {
  shader_ = new Shader(kVertexShaderPath, kFragmentShaderPath);
  glGenVertexArrays(1, &vao_);
  glGenBuffers(1, &vbo_);
  renderer::primitives.insert(primitives.end(), this);
}

Line::~Line() {
  delete shader_;
  glDeleteVertexArrays(1, &vao_);
  glDeleteBuffers(1, &vbo_);
  std::remove(renderer::primitives.begin(), renderer::primitives.end(), this);
}

void Line::Draw() {
  glDrawArrays(GL_LINE_STRIP, 0, 2);
}

void Line::SetData() {

  float vertices[] = {start_.position.x, start_.position.y, start_.position.z,
					  end_.position.x, end_.position.y, end_.position.z};

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
  glEnableVertexAttribArray(0);

  glm::mat4 model{1.0f};
  model = glm::translate(model, pivot_.position);
  model = glm::rotate(model, angle(pivot_.rotation), axis(pivot_.rotation));
  model = glm::scale(model, pivot_.scale);
  glm::mat4 mvp = Camera::ProjectionMatrix() * Camera::ViewMatrix() * model;

  glLineWidth(material_.width);

  shader_->SetMat4Uniform("u_MVP", mvp);
  shader_->SetVec4Uniform("u_color", material_.color);
}

void Line::Bind() {
  shader_->Use();
  glBindVertexArray(vao_);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
}

void Line::Unbind() {
  glBindVertexArray(0);
  glLineWidth(1);
}

void Line::SetStart(const Transform &transform) {
  start_ = transform;
}

void Line::SetEnd(const Transform &transform) {
  end_ = transform;
}

void Line::SetPivot(const Transform &transform) {
  pivot_ = transform;
}

Line::Line(Line &&line) noexcept {
  vbo_ = line.vbo_;
  vao_ = line.vao_;
  shader_ = line.shader_;
  start_ = line.start_;
  end_ = line.end_;
  pivot_ = line.pivot_;
  material_ = line.material_;
}
Line &Line::operator=(Line &&a) noexcept {
  return *this;
}

} // Renderer
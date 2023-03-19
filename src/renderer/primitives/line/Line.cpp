#include "Line.h"
#include "camera/Camera.h"
#include "Provider.h"

const std::string VERTEX_SHADER_PATH = "./resources/shaders/line/line.vert";
const std::string FRAGMENT_SHADER_PATH = "./resources/shaders/line/line.frag";

namespace Renderer
{

	Line::Line() {
		_shader = new Shader(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);
		glGenVertexArrays(1, &_vao);
		glGenBuffers(1, &_vbo);
		Renderer::primitives.insert(primitives.end(), this);
	}

	Line::~Line() {
		delete _shader;
		glDeleteVertexArrays(1, &_vao);
		glDeleteBuffers(1, &_vbo);
		std::remove(Renderer::primitives.begin(), Renderer::primitives.end(), this);
	}

	void Line::Draw() {
		glDrawArrays(GL_LINE_STRIP, 0, 2);
	}

	void Line::SetData() {

		float vertices[] = { Start.x, Start.y, Start.z,
							 End.x, End.y, End.z };

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
		glEnableVertexAttribArray(0);

		glm::mat4 model{ 1.0f };
		model = glm::translate(model, Position);
		model = glm::scale(model, Scale);

		glm::mat4 mvp = Camera::GetProjectionMatrix() * Camera::GetViewMatrix() * model;

		glLineWidth(Material.Width);

		_shader->SetMat4Uniform("u_MVP", mvp);
		_shader->SetVec4Uniform("u_color", Material.Color);
	}

	void Line::Bind() {
		_shader->Use();
		glBindVertexArray(_vao);
		glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	}

	void Line::Unbind() {
		glBindVertexArray(0);
		glLineWidth(1);
	}

} // Renderer
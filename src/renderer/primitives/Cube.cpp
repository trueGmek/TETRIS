#include "Cube.h"

const std::string VERTEX_SHADER_PATH = "/home/gmek/Dev/C++/OpenGL/tetris/resources/shaders/vertex.glsl";
const std::string FRAGMENT_SHADER_PATH = "/home/gmek/Dev/C++/OpenGL/tetris/resources/shaders/fragment.glsl";

namespace Renderer
{
	Cube::Cube()
	{
		_shader = new Shader(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);

		glGenVertexArrays(1, &_vao);
		glGenBuffers(1, &_vbo);
		glGenBuffers(1, &_ebo);

		glBindVertexArray(_vao);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Primitives::CubeIndices), Primitives::CubeIndices, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, _vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(Primitives::CubeVertices), Primitives::CubeVertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
		glEnableVertexAttribArray(0);
	}

	void Cube::SetTransform(const Transform& transform)
	{
		_transform = transform;
	}

	void Cube::Draw()
	{
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}

	void Cube::SetMaterial(const Material& material)
	{
		_material = material;
	}

	void Cube::SetData()
	{
		glm::mat4 model{ 1.0f };
		model = glm::translate(model, _transform.Position);
		model = glm::rotate(model, angle(_transform.Rotation), axis(_transform.Rotation));
		model = glm::scale(model, _transform.Scale);
		glm::mat4 trans = Camera::GetProjectionMatrix() * model;
//		glm::mat4 trans = model;

		_shader->SetMat4Uniform("Transform", trans);
		_shader->SetVec4Uniform("Color", _material.Color);
	}
} // Renderer
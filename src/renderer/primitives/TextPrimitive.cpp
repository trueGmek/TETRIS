#include "TextPrimitive.h"
#include "Character.h"
#include "Text.h"
#include "Provider.h"
#include "camera/Camera.h"

const std::string VERTEX_SHADER_PATH = "./resources/shaders/text/text.vert";
const std::string FRAGMENT_SHADER_PATH = "./resources/shaders/text/text.frag";
namespace Renderer
{
	TextPrimitive::TextPrimitive() {

		_shader = new Shader(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);

		glGenVertexArrays(1, &_vao);
		glGenBuffers(1, &_vbo);

		glBindVertexArray(_vao);
		glBindBuffer(GL_ARRAY_BUFFER, _vbo);

		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, nullptr, GL_DYNAMIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		Renderer::primitives.insert(primitives.end(), this);
	}

	void TextPrimitive::Bind() {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		_shader->Use();
		glActiveTexture(GL_TEXTURE0);
		glBindVertexArray(_vao);

	}

	void TextPrimitive::SetData() {
		glm::mat4 model{ 1.0f };
		model = glm::translate(model, Position);
		model = glm::rotate(model, angle(Rotation), axis(Rotation));
		model = glm::scale(model, Scale);
		glm::mat4 mvp = Camera::GetProjectionMatrix() * Camera::GetViewMatrix() * model;

		_shader->SetVec3Uniform("textColor", MyMaterial.Color);
		_shader->SetMat4Uniform("MVP", mvp);
	}

	void TextPrimitive::Draw() {
		std::string::const_iterator c;

		glm::vec2 offset{ 0.0f };

		for (c = Text.begin(); c != Text.end(); c++) {
			Renderer::Character ch = Renderer::Text::Characters[*c];

			float xpos = ch.Bearing.x + offset.x;
			float ypos = (ch.Size.y - ch.Bearing.y);

			float w = ch.Size.x;
			float h = ch.Size.y;

			float vertices[6][4] = {
				{ xpos + w, ypos, 1.0f, 1.0f },
				{ xpos, ypos - h, 0.0f, 0.0f },
				{ xpos + w, ypos - h, 1.0f, 0.0f },

				{ xpos + w, ypos, 1.0f, 1.0f },
				{ xpos, ypos, 0.0f, 1.0f },
				{ xpos, ypos - h, 0.0f, 0.0f },

			};

			// render glyph texture over quad
			glBindTexture(GL_TEXTURE_2D, ch.TextureID);

			// update content of VBO memory
			glBindBuffer(GL_ARRAY_BUFFER, _vbo);
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			// render quad
			glDrawArrays(GL_TRIANGLES, 0, 6);
			// now advance cursors for next glyph (note that advance is number of 1/64 pixels)
			offset.x += (ch.Advance >> 6); // bitshift by 6 to get value in pixels (2^6 = 64)
		}
	}

	void TextPrimitive::Unbind() {
		glBindVertexArray(0);
	}

	TextPrimitive::~TextPrimitive() {

		glDeleteVertexArrays(1, &_vao);
		glDeleteBuffers(1, &_vbo);

		delete _shader;
		std::remove(primitives.begin(), primitives.end(), this);
	}
} // Renderer
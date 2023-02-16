#include "Cube.h"
#include "../../Provider.h"
#include "../../Renderer.h"

#define STB_IMAGE_IMPLEMENTATION

#include "../../../external/stb_image.h"

const std::string VERTEX_SHADER_PATH = "/home/gmek/Dev/C++/OpenGL/tetris/resources/shaders/cube/cube.vert";
const std::string FRAGMENT_SHADER_PATH = "/home/gmek/Dev/C++/OpenGL/tetris/resources/shaders/cube/cube.frag";
const std::string TEXTURE_PATH = "/home/gmek/Dev/C++/OpenGL/tetris/resources/block_texture.jpg";

float const VERTEX_ATTRIBUTES[] = {
	-0.5, 0.5, 0, 0.0, 1.0,    //TOP LEFT
	0.5, 0.5, 0, 1.0, 1.0,    // TOP RIGHT
	-0.5, -0.5, 0, 0.0, 0.0, // BOTTOM LEFT
	0.5, -0.5, 0, 1.0, 0.0 //BOTTOM RIGHT
};

unsigned int const INDICES[] = {
	0, 2, 3,
	0, 1, 3
};

namespace Renderer
{
	//TODO: THERE IS SOMETHING WRONG WITH THE TEXTURES BECAUSE COLORS IS SET IN THE SHADER
	// WEIRD, FOR A SPLIT SECOND YOU CAN SEE THE CORRECT TEXTURE
	Cube::Cube() {
		_shader = new Shader(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);

		int width, height, nrChannels;
		unsigned char* data = stbi_load(TEXTURE_PATH.c_str(), &width, &height, &nrChannels, 0);

		glGenVertexArrays(1, &_vao);
		glGenBuffers(1, &_vbo);
		glGenBuffers(1, &_ebo);
		glGenTextures(1, &_texture);

		glBindVertexArray(_vao);

		glBindTexture(GL_TEXTURE_2D, _texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			std::cout << "Unable to load texture at: " << TEXTURE_PATH << std::endl;
		}

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(INDICES), INDICES, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, _vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(VERTEX_ATTRIBUTES), VERTEX_ATTRIBUTES, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		Renderer::primitives.insert(primitives.end(), this);

		stbi_image_free(data);
	}

	Cube::~Cube() {
		glDeleteVertexArrays(1, &_vao);
		glDeleteBuffers(1, &_vbo);
		glDeleteBuffers(1, &_ebo);

		delete _shader;
		std::remove(primitives.begin(), primitives.end(), this);
	}

	void Cube::Draw() {
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}

	void Cube::SetData() {
		glm::mat4 model{ 1.0f };
		model = glm::translate(model, MyTransform.Position);
		model = glm::rotate(model, angle(MyTransform.Rotation), axis(MyTransform.Rotation));
		model = glm::scale(model, MyTransform.Scale);

		glm::mat4 mvp = Camera::ProjectionMatrix() * Camera::ViewMatrix() * model;

		_shader->SetMat4Uniform("MVP", mvp);
		_shader->SetVec4Uniform("Color", MyMaterial.color);
	}

	void Cube::Bind() {
		glBindVertexArray(_vao);
		_shader->Use();
		glBindTexture(GL_TEXTURE_2D, _texture);
	}

	void Cube::Unbind() {
		glBindVertexArray(0);
	}
} // Renderer
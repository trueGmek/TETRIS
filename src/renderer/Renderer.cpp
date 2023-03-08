#include "Renderer.h"
#include "shader/Shader.h"
#include "Provider.h"
#include "Text.h"

GLFWwindow* Renderer::window;

float Renderer::windowWidth = (float)Renderer::kInitialWidth;
float Renderer::windowHeight = (float)Renderer::kInitialHeight;

const std::string FONT_PATH{ "../resources/FiraCode-Bold.ttf" };

static void ErrorCallback(int error, const char* description) {
	std::cout << "Error: " << description << std::endl;
}

void FramebufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
	Renderer::windowWidth = width;
	Renderer::windowHeight = height;
}

bool Renderer::Initialize() {
	if (!glfwInit())
		return false;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(kInitialWidth, kInitialHeight, "TETRIS", nullptr, nullptr);
	if (!window)
		return false;
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to Initialize OpenGL context" << std::endl;
		return false;
	}

	glfwSetErrorCallback(ErrorCallback);

	glViewport(0, 0, kInitialWidth, kInitialHeight);
	glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	glEnable(GL_DEPTH_TEST);

	if (!Renderer::Text::Initialize(FONT_PATH)) {
		return false;
	}
	GenerateCharacterTextures();
	Renderer::Text::Deinitialize();

	return true;
}

void Renderer::Terminate() {
	if (window != nullptr)
		glfwDestroyWindow(window);

	glfwTerminate();
}

void Renderer::Update() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (auto primitive : primitives) {
		primitive->Bind();
		primitive->SetData();
		primitive->Draw();
		primitive->Unbind();
	}

	glfwSwapBuffers(window);
	glfwPollEvents();
}

bool Renderer::IsWindowClosing() {
	return glfwWindowShouldClose(window);
}

void Renderer::GenerateCharacterTextures() {

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // disable byte-alignment restriction

	for (unsigned char c = 0; c < 128; ++c) {
		FT_GlyphSlot glyphSlot = Renderer::Text::GetGlyph(c);

		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		if (c == 'c') {
			std::cout << "Texture id for c: " << texture << std::endl;
		}
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RED,
			glyphSlot->bitmap.width,
			glyphSlot->bitmap.rows,
			0,
			GL_RED,
			GL_UNSIGNED_BYTE,
			glyphSlot->bitmap.buffer
		);

		// set texture options
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		Character character = {
			texture,
			glm::ivec2(glyphSlot->bitmap.width, glyphSlot->bitmap.rows),
			glm::ivec2(glyphSlot->bitmap_left, glyphSlot->bitmap_top),
			static_cast<unsigned int>(glyphSlot->advance.x)
		};

		Renderer::Text::Characters.insert(std::pair<char, Character>(c, character));

		glBindTexture(GL_TEXTURE_2D, 0);
	}

	glPixelStorei(GL_UNPACK_ALIGNMENT, 0);

}

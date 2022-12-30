#include "Renderer.h"
#include "shader/Shader.h"
#include "../debug/Debug.h"
#include "Provider.h"

GLFWwindow* Renderer::window;

float Renderer::windowWidth = (float)Renderer::kInitialWidth;
float Renderer::windowHeight = (float)Renderer::kInitialHeight;

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

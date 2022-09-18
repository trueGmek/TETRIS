#include "Renderer.h"
#include "shader/Shader.h"
#include "../debug/Debug.h"
#include "Provider.h"

GLFWwindow *renderer::window;

static void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	glfwSetWindowShouldClose(window, GLFW_TRUE);
}

static void ErrorCallback(int error, const char *description) {
  std::cout << "Error: " << description << std::endl;
}

static void FramebufferSizeCallback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

bool renderer::Initialize() {
  if (!glfwInit())
	return false;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  window = glfwCreateWindow(kInitialWidth, kInitialHeight, "TETRIS", nullptr, nullptr);
  if (!window)

	return false;
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
	std::cout << "Failed to Initialize OpenGL context" << std::endl;
	return false;
  }

  glfwSetKeyCallback(window, KeyCallback);
  glfwSetErrorCallback(ErrorCallback);

  glViewport(0, 0, kInitialWidth, kInitialHeight);
  glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

  glEnable(GL_DEPTH_TEST);

  return true;
}

void renderer::Terminate() {
  if (window != nullptr)
	glfwDestroyWindow(window);

  glfwTerminate();
}

void renderer::Update() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  for (auto primitive : primitives) {
	primitive->Bind();
	primitive->SetData();
	primitive->Draw();
	primitive->Unbind();
  }

  glfwPollEvents();
  glfwSwapBuffers(window);
}

bool renderer::IsWindowClosing() {
  return glfwWindowShouldClose(window);
}

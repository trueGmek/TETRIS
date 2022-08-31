#include "Renderer.h"
#include "shader/Shader.h"
#include "../debug/Debug.h"

GLFWwindow* MyWindow;

std::queue<Renderer::Primitive*> Renderer::_primitivesQueue{};

static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

static void ErrorCallback(int error, const char* description)
{
	std::cout << "Error: " << description << std::endl;
}

static void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

bool Renderer::Initialize()
{
	if (!glfwInit())
		return false;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	MyWindow = glfwCreateWindow(INITIAL_WIDTH, INITIAL_HEIGHT, "TETRIS", nullptr, nullptr);
	if (!MyWindow)

		return false;
	glfwMakeContextCurrent(MyWindow);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to Initialize OpenGL context" << std::endl;
		return false;
	}

	glfwSetKeyCallback(MyWindow, KeyCallback);
	glfwSetErrorCallback(ErrorCallback);

	glViewport(0, 0, INITIAL_WIDTH, INITIAL_HEIGHT);
	glfwSetFramebufferSizeCallback(MyWindow, FramebufferSizeCallback);

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	glEnable(GL_DEPTH_TEST);

	return true;
}

void Renderer::Terminate()
{
	if (MyWindow != nullptr)
		glfwDestroyWindow(MyWindow);

	glfwTerminate();
}

void Renderer::Update()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	while (!Renderer::_primitivesQueue.empty())
	{

		Renderer::_primitivesQueue.front()->Bind();
		Renderer::_primitivesQueue.front()->SetData();
		Renderer::_primitivesQueue.front()->Draw();
		Renderer::_primitivesQueue.front()->Unbind();

		Renderer::_primitivesQueue.pop();
	}

	glfwPollEvents();
	glfwSwapBuffers(MyWindow);
}

bool Renderer::IsWindowClosing()
{
	return glfwWindowShouldClose(MyWindow);
}

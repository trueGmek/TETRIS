#include "Renderer.h"
#include "shader/Shader.h"
#include "Primitives.h"

GLFWwindow* MyWindow;
Shader* basicShader;
unsigned int Vbo, Vao, Ebo;

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
	MyWindow = glfwCreateWindow(InitialWidth, InitialHeight, "TETRIS", nullptr, nullptr);
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

	glViewport(0, 0, InitialWidth, InitialHeight);
	glfwSetFramebufferSizeCallback(MyWindow, FramebufferSizeCallback);

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	glGenVertexArrays(1, &Vao);
	glGenBuffers(1, &Vbo);
	glGenBuffers(1, &Ebo);

	glBindVertexArray(Vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Primitives::CubeIndices), Primitives::CubeIndices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, Vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Primitives::CubeVertices), Primitives::CubeVertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	basicShader = new Shader("/home/gmek/Dev/C++/OpenGL/tetris/resources/shaders/vertex.glsl",
		"/home/gmek/Dev/C++/OpenGL/tetris/resources/shaders/fragment.glsl");

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
	glClear(GL_COLOR_BUFFER_BIT);

	basicShader->Use();
	glBindVertexArray(Vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glfwPollEvents();
	glfwSwapBuffers(MyWindow);
}

bool Renderer::IsWindowClosing()
{
	return glfwWindowShouldClose(MyWindow);
}

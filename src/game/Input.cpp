#include "Input.h"
#include "Renderer.h"
#include "GameController.h"

int KEY_W, KEY_S, KEY_A, KEY_D, KEY_F1, KEY_F2;

int KEY_ESCAPE;
int KEY_SPACE;
int KEY_TAB;

bool Input::Initialize() {

	SetKeyScancodes();

	glfwSetKeyCallback(Renderer::window, InputKeyCallback);

	return true;
}

void Input::SetKeyScancodes() {
	KEY_W = glfwGetKeyScancode(GLFW_KEY_W);
	KEY_S = glfwGetKeyScancode(GLFW_KEY_S);
	KEY_A = glfwGetKeyScancode(GLFW_KEY_A);
	KEY_D = glfwGetKeyScancode(GLFW_KEY_D);
	KEY_F1 = glfwGetKeyScancode(GLFW_KEY_F1);
	KEY_F2 = glfwGetKeyScancode(GLFW_KEY_F2);

	KEY_ESCAPE = glfwGetKeyScancode(GLFW_KEY_ESCAPE);
	KEY_SPACE = glfwGetKeyScancode(GLFW_KEY_SPACE);
	KEY_TAB = glfwGetKeyScancode(GLFW_KEY_TAB);
}

void Input::InputKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {

	auto* gameController = (GameController*)glfwGetWindowUserPointer(window);

	if (scancode == KEY_A && action == GLFW_PRESS)
		gameController->MoveTetrominoLeft();

	if (scancode == KEY_D && action == GLFW_PRESS)
		gameController->MoveTetrominoRight();

	if (scancode == KEY_SPACE && action == GLFW_PRESS)
		gameController->DropTetromino();

	if (scancode == KEY_W && action == GLFW_PRESS)
		gameController->RotateClockwise();

	if (scancode == KEY_S && action == GLFW_PRESS)
		gameController->RotateCounterclockwise();

	if (scancode == KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);

	if (scancode == KEY_F1 && action == GLFW_PRESS)
		gameController->DebugToggleUpdate();

	if (scancode == KEY_F2 && action == GLFW_PRESS)
		gameController->StepUpdate();

	if (scancode == KEY_TAB && action == GLFW_PRESS)
		gameController->SwapPieces();
}

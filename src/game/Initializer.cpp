#include "Initializer.h"
#include "GameController.h"
#include "Input.h"

GameController* Game::GameController;

bool Game::Initialize() {

	Input::Initialize();
	GameController = new class GameController();

	return true;
}

bool Game::Deinitialize() {
	delete GameController;

	return true;
}

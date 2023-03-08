#include "Initializer.h"
#include "GameController.h"
#include "Input.h"

GameController* gameController;

bool Initializer::Initialize() {

	Input::Initialize();
	gameController = new GameController();
	

	return true;
}

bool Initializer::Deinitialize() {
	delete gameController;

	return true;
}

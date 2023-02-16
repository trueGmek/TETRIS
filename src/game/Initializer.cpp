#include "Initializer.h"
#include "GameController.h"

GameController* gameController;

bool Initializer::Initialize() {

	gameController = new GameController();

	return true;
}

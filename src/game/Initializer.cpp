#include "Initializer.h"
#include "../renderer/primitives/line/Line.h"
#include "Grid/Board.h"
#include "GameController.h"

GameController* gameController;

bool Initializer::Initialize() {
	gameController = new GameController();

	return true;
}

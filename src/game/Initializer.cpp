#include "Initializer.h"
#include "GameCube.h"
#include "../renderer/primitives/line/Line.h"
#include "Grid/Board.h"
#include "GameController.h"

Board* board;
GameController* gameController;

bool Initializer::Initialize() {
	board = new Board(glm::vec3{ 400, 400, 0 }, glm::vec2{ 400, 600 });
	gameController = new GameController(board);

	return true;
}

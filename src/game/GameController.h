#ifndef TETRIS_SRC_GAME_GAMECONTROLLER_H
#define TETRIS_SRC_GAME_GAMECONTROLLER_H

#include "GameObject.h"

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <array>
#include "Grid/Board.h"
#include "Grid/Piece.h"
#include "Grid/Tetromino.h"

class GameController : public GameObject
{

private:
	bool _isUpdating = false;
	Board _board{ glm::vec3{ 400, 400, 0 }, glm::vec2{ 400, 600 }};

	EShape _nextShape;

	Tetromino* _current;

public:
	explicit GameController();

	void Update() override;

	void MoveTetrominoRight();
	void MoveTetrominoLeft();
	void RotateClockwise();
	void RotateCounterclockwise();
	void DropTetromino();
	void DebugToggleUpdate();
	void StepUpdate();

private:
	bool IsRowFull(int row);
	void ClearRow(int row);
	void MoveRowsDown(int formRow);
	void ClearFullRows();
	void SetNewPiece();

	void EndGame();
};

#endif //TETRIS_SRC_GAME_GAMECONTROLLER_H

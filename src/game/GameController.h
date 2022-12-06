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
	Board* _board;
	std::array<Piece, 200> _pieces;
	Tetromino _current;

public:
	explicit GameController(Board* grid);

	void Start() override;
	void Update() override;

	void OnDestroy() override {
	}

	void OnEnable() override {
	}

	void OnDisable() override {
	}

	void MoveTetrominoRight();
	void MoveTetrominoLeft();
	void RotateClockwise();
	void RotateCounterclockwise();
	void DropTetromino();
	void DebugToggleUpdate();
	void StepUpdate();

private:
	bool IsRowFull(int row) const;
	void ClearRow(int row);
	void MoveRowsDown(int formRow);
	void ClearFullRows();
	void SetNewPiece();
};

#endif //TETRIS_SRC_GAME_GAMECONTROLLER_H

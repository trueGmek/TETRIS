#ifndef TETRIS_SRC_GAME_GAMECONTROLLER_H
#define TETRIS_SRC_GAME_GAMECONTROLLER_H

#include "GameObject.h"

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <array>
#include "Grid/Tetromino.h"
#include "Grid/Board.h"
#include "Grid/Piece.h"
#include "../renderer/primitives/TextPrimitive.h"
#include "PiecePreview.h"
#include "GameUI.h"

class GameController : public GameObject
{

private:
	bool _isUpdating = false;
	bool _isHoldingShape = false;

	EShape _nextShape;
	EShape _heldShape{};

	Tetromino* _current;

	Board _board{ glm::vec3{ 400, 400, 0 }, glm::vec2{ 400, 600 }};

	GameUI* ui;

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
	void SwapPieces();

private:
	void ClearFullRows();
	void GenerateNewPiece();
	void CreateNewPiece(EShape shape);

	void EndGame();

	bool _isAbleToSwap = true;
	static double CalculateMoveTime();
};

#endif //TETRIS_SRC_GAME_GAMECONTROLLER_H

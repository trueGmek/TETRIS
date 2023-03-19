#pragma once

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <array>
#include "Grid/Tetromino.h"
#include "Grid/Board.h"
#include "Grid/Piece.h"
#include "primitives/TextPrimitive.h"
#include "PiecePreview.h"
#include "GameUI.h"
#include "GameObject.h"

class GameController : public GameObject
{

private:
	bool _isUpdating = true;
	bool _isHoldingShape = false;

	EShape _nextShape;
	EShape _heldShape{};

	Board _board{ glm::vec3{ 400, 400, -1 }, glm::vec2{ 400, 600 }};
	GameUI _ui{};

	Tetromino* _current;

public:
	explicit GameController();
	~GameController();

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

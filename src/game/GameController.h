#ifndef TETRIS_SRC_GAME_GAMECONTROLLER_H
#define TETRIS_SRC_GAME_GAMECONTROLLER_H

#include "GameObject.h"

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <array>
#include "Grid/Board.h"
#include "Grid/Piece.h"
#include "Grid/Tetromino.h"
#include "../renderer/primitives/TextPrimitive.h"
#include "PiecePreview.h"

class GameController : public GameObject
{

private:
	bool _isUpdating = false;
	bool _isHoldingShape = false;

	EShape _nextShape;
	EShape _heldShape{};

	Tetromino* _current;

	Renderer::TextPrimitive* _scoreTitle;
	Renderer::TextPrimitive* _scoreText;
	Renderer::TextPrimitive* _nextPieceTitle;
	Renderer::TextPrimitive* _heldPieceTitle;

	PiecePreview* _nextPiecePreview;
	PiecePreview* _heldPiecePreview;

	Board _board{ glm::vec3{ 400, 400, 0 }, glm::vec2{ 400, 600 }};

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
	bool IsRowFull(int row);
	void ClearRow(int row);
	void MoveRowsDown(int formRow);
	void ClearFullRows();
	void GenerateNewPiece();
	void SetNewPiece(EShape shape);

	void EndGame();

	bool _isAbleToSwap = true;
	void SetUpGUI();
};

#endif //TETRIS_SRC_GAME_GAMECONTROLLER_H

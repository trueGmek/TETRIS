#ifndef TETRIS_SRC_GAME_GRID_BOARD_H
#define TETRIS_SRC_GAME_GRID_BOARD_H

#include <map>
#include "../../renderer/primitives/cube/Cube.h"
#include "../GameObject.h"
#include "../../renderer/primitives/Colors.h"
#include "../../renderer/primitives/line/Line.h"
#include "GridCell.h"

class Board : GameObject
{
public:
	static const int ACROSS{ 10 };
	static const int DOWN{ 20 };

private:

	Renderer::Line _top;
	Renderer::Line _bottom;
	Renderer::Line _left;
	Renderer::Line _right;

	glm::vec3 _center{};
	glm::vec2 _size{};
	glm::vec3 _cellSize{};

	std::array<Renderer::Cube, ACROSS * DOWN> _cubesRenderer;
	std::array<std::array<GridCell, DOWN>, ACROSS> _cells{};

public:

	Board(glm::vec3 center, glm::vec2 size);

	Piece* GetPiece(glm::ivec2 position);
	Piece* GetPiece(int x, int y);

	GridCell* GetGridCell(glm::ivec2 position);
	GridCell* GetGridCell(int x, int y);

	void SetPiece(glm::ivec2 position, Piece* piece);
	void SetPiece(int x, int y, Piece* piece);

private:
	void Update() override;

	void EnableVisibleSquares(const glm::vec3& center, const glm::vec2& size);
	void InitializeSquares(const glm::vec3& center, const glm::vec2& size);
	void SetUpGameState();
};

#endif //TETRIS_SRC_GAME_GRID_BOARD_H

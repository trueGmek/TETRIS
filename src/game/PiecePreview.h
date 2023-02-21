#ifndef TETRIS_SRC_GAME_PIECEPREVIEW_H
#define TETRIS_SRC_GAME_PIECEPREVIEW_H

#include <array>
#include "../renderer/primitives/cube/Cube.h"
#include "Grid/TetrominoData.h"

class PiecePreview
{

public:
	Transform MyTransform{};
	void SetShape(EShape shape);
	void SetActive(bool isActive);

	explicit PiecePreview(glm::vec3 cellSize);

private:
	std::array<Renderer::Cube, 4> _previewCubes{};
	glm::vec3 _cellSize;

};

#endif //TETRIS_SRC_GAME_PIECEPREVIEW_H

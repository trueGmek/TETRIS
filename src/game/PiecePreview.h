#pragma once

#include <array>
#include "primitives/cube/Cube.h"
#include "Grid/TetrominoData.h"
#include "Transform.h"

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

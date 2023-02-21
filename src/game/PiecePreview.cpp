//
// Created by gmek on 2/16/23.
//

#include "PiecePreview.h"

void PiecePreview::SetShape(EShape shape) {

	for (int i = 0; i < 4; ++i) {
		_previewCubes[i].MyTransform.Position =
			MyTransform.Position + glm::vec3{ TetrominoData[shape].Coordinates[i], 0 } * _cellSize;
		_previewCubes[i].MyMaterial.color = TetrominoData[shape].Color;
		_previewCubes[i].MyTransform.Scale = _cellSize;
	}

}

PiecePreview::PiecePreview(glm::vec3 cellSize) : _cellSize(cellSize) {
}

void PiecePreview::SetActive(bool isActive) {
	for (int i = 0; i < 4; ++i) {
		_previewCubes[i].MyTransform.Scale = isActive ? _cellSize : glm::vec3{ 0 };
	}

}

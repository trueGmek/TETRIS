#include "PiecePreview.h"

void PiecePreview::SetShape(EShape shape) {

	for (int i = 0; i < 4; ++i) {
		_previewCubes[i].Position =
			MyTransform.Position + glm::vec3{ TetrominoData[shape].Coordinates[i], 0 } * _cellSize;
		_previewCubes[i].MyMaterial.Color = TetrominoData[shape].Color;
		_previewCubes[i].Scale = _cellSize;
	}

}

PiecePreview::PiecePreview(glm::vec3 cellSize) : _cellSize(cellSize) {
}

void PiecePreview::SetActive(bool isActive) {
	for (int i = 0; i < 4; ++i) {
		_previewCubes[i].Scale = isActive ? _cellSize : glm::vec3{ 0 };
	}

}

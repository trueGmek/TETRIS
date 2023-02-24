#ifndef TETRIS_SRC_GAME_GAMEUI_H
#define TETRIS_SRC_GAME_GAMEUI_H

#include "../renderer/primitives/TextPrimitive.h"
#include "PiecePreview.h"

class GameUI
{

public:
	Renderer::TextPrimitive* ScoreTitle{ new Renderer::TextPrimitive() };
	Renderer::TextPrimitive* ScoreText{ new Renderer::TextPrimitive() };
	Renderer::TextPrimitive* NextPieceTitle{ new Renderer::TextPrimitive() };
	Renderer::TextPrimitive* HeldPieceTitle{ new Renderer::TextPrimitive() };
	Renderer::TextPrimitive* LostText{ new Renderer::TextPrimitive() };

	PiecePreview* NextPiecePreview{ new PiecePreview(glm::vec3{ 40, 40, 1 }) };
	PiecePreview* HeldPiecePreview{ new PiecePreview(glm::vec3{ 40, 40, 1 }) };

public:
	void SetUpGui(EShape nextShape, EShape heldShape);
};

#endif //TETRIS_SRC_GAME_GAMEUI_H

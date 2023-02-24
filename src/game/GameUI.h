#ifndef TETRIS_SRC_GAME_GAMEUI_H
#define TETRIS_SRC_GAME_GAMEUI_H

#include "../renderer/primitives/TextPrimitive.h"
#include "PiecePreview.h"

class GameUI
{

public:
	Renderer::TextPrimitive* ScoreTitle;
	Renderer::TextPrimitive* ScoreText;
	Renderer::TextPrimitive* NextPieceTitle;
	Renderer::TextPrimitive* HeldPieceTitle;

	PiecePreview* NextPiecePreview;
	PiecePreview* HeldPiecePreview;

public:

	void SetUpGui(EShape nextShape, EShape heldShape);
};

#endif //TETRIS_SRC_GAME_GAMEUI_H

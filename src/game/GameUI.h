#pragma once

#include "primitives/TextPrimitive.h"
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
	void SetUpGui(EShape nextShape, EShape heldShape) const;
};
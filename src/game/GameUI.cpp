//
// Created by gmek on 2/24/23.
//

#include "GameUI.h"
#include "PiecePreview.h"

void GameUI::SetUpGui(EShape nextShape, EShape heldShape) {
	NextPiecePreview->MyTransform.Position = glm::vec3{ 725, 165, 0 };
	NextPiecePreview->SetShape(nextShape);

	HeldPiecePreview->MyTransform.Position = glm::vec3{ 725, 375, 0 };
	HeldPiecePreview->SetShape(heldShape);
	HeldPiecePreview->SetActive(false);

	ScoreText->MyTransform.Position = glm::vec3{ 75, 100, 0 };
	ScoreText->MyTransform.Scale = glm::vec3{ 1.0f };
	ScoreText->MyMaterial.color = glm::vec4{ 1.0f };

	NextPieceTitle->MyTransform.Position = glm::vec3{ 625, 75, 0 };
	NextPieceTitle->MyTransform.Scale = glm::vec3{ 0.5f };
	NextPieceTitle->MyMaterial.color = glm::vec4{ 1.0f };
	NextPieceTitle->Text = "NEXT PIECE";

	HeldPieceTitle->MyTransform.Position = glm::vec3{ 625, 300, 0 };
	HeldPieceTitle->MyTransform.Scale = glm::vec3{ 0.5f };
	HeldPieceTitle->MyMaterial.color = glm::vec4{ 1.0f };
	HeldPieceTitle->Text = "HELD PIECE";

	ScoreTitle->MyTransform.Position = glm::vec3{ 50, 50, 0 };
	ScoreTitle->MyTransform.Scale = glm::vec3{ .5f };
	ScoreTitle->MyMaterial.color = glm::vec4{ 1.0f };
	ScoreTitle->Text = "SCORE";

	LostText->MyTransform.Position = glm::vec3{ 160, 400,  0};
	LostText->MyTransform.Scale = glm::vec3{0.0f};
	LostText->MyMaterial.color = glm::vec4{ 0.0f };
	LostText->Text = "YOU LOST";
}
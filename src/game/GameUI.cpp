
#include "GameUI.h"
#include "PiecePreview.h"

void GameUI::SetUpGui(EShape nextShape, EShape heldShape) const {
	NextPiecePreview->MyTransform.Position = glm::vec3{ 725, 165, 0 };
	NextPiecePreview->SetShape(nextShape);

	HeldPiecePreview->MyTransform.Position = glm::vec3{ 725, 375, 0 };
	HeldPiecePreview->SetShape(heldShape);
	HeldPiecePreview->SetActive(false);

	ScoreText->Position = glm::vec3{ 75, 100, 0 };
	ScoreText->Scale = glm::vec3{ 1.0f };
	ScoreText->MyMaterial.Color = glm::vec4{ 1.0f };

	NextPieceTitle->Position = glm::vec3{ 625, 75, 0 };
	NextPieceTitle->Scale = glm::vec3{ 0.5f };
	NextPieceTitle->MyMaterial.Color = glm::vec4{ 1.0f };
	NextPieceTitle->Text = "NEXT PIECE";

	HeldPieceTitle->Position = glm::vec3{ 625, 300, 0 };
	HeldPieceTitle->Scale = glm::vec3{ 0.5f };
	HeldPieceTitle->MyMaterial.Color = glm::vec4{ 1.0f };
	HeldPieceTitle->Text = "HELD PIECE";

	ScoreTitle->Position = glm::vec3{ 50, 50, 0 };
	ScoreTitle->Scale = glm::vec3{ .5f };
	ScoreTitle->MyMaterial.Color = glm::vec4{ 1.0f };
	ScoreTitle->Text = "SCORE";

	LostText->Position = glm::vec3{ 160, 400, 0 };
	LostText->Scale = glm::vec3{ 0.0f };
	LostText->MyMaterial.Color = glm::vec4{ 0.0f };
	LostText->Text = "YOU LOST";
}
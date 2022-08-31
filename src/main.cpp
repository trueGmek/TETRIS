#include "renderer/Renderer.h"
#include "game/Game.h"

int main()
{
	Renderer::Initialize();
	Game::Initialize();

	while (!Renderer::IsWindowClosing())
	{
		Game::Update();
		Renderer::Update();
	}

	Game::Terminate();
	Renderer::Terminate();
}

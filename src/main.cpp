#include "Initializer.h"
#include "Renderer.h"
#include "Engine.h"

int main() {
	Renderer::Initialize();
	Game::Initialize();

	while (!Renderer::IsWindowClosing()) {
		Engine::Update();
		Renderer::Update();
	}

	Game::Deinitialize();

	Engine::Terminate();
	Renderer::Terminate();
}

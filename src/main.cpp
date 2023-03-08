#include "Renderer.h"
#include "Engine.h"
#include "game/Initializer.h"

int main() {
	Renderer::Initialize();
	Initializer::Initialize();

	while (!Renderer::IsWindowClosing()) {
		Engine::Update();
		Renderer::Update();
	}

	Initializer::Deinitialize();

	Engine::Terminate();
	Renderer::Terminate();
}

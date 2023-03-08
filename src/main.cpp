#include "renderer/Renderer.h"
#include "engine/Engine.h"
#include "game/Initializer.h"

int main() {
	Renderer::Initialize();

	Initializer::Initialize();

	while (!Renderer::IsWindowClosing()) {
		engine::Update();
		Renderer::Update();
	}

	Initializer::Deinitialize();

	engine::Terminate();
	Renderer::Terminate();
}

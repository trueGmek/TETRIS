#include "renderer/Renderer.h"
#include "engine/Engine.h"

int main() {
	renderer::Initialize();
	engine::Initialize();

	engine::StartGameObjects();
	engine::EnableGameObjects();

	while (!renderer::IsWindowClosing()) {
		engine::Update();
		renderer::Update();
	}

	engine::Terminate();
	renderer::Terminate();
}

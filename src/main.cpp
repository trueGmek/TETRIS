#include "renderer/Renderer.h"
#include "engine/Engine.h"

int main() {
	renderer::Initialize();
	engine::Initialize();

	while (!renderer::IsWindowClosing()) {
		engine::Update();
		renderer::Update();
	}

	engine::Terminate();
	renderer::Terminate();
}

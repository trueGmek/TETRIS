#include "renderer/Renderer.h"
#include "engine/Engine.h"

int main() {
	Renderer::Initialize();
	engine::Initialize();

	while (!Renderer::IsWindowClosing()) {
		engine::Update();
		Renderer::Update();
	}

	engine::Terminate();
	Renderer::Terminate();
}

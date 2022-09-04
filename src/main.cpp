#include "renderer/Renderer.h"
#include "game/Game.h"

int main() {
  renderer::Initialize();
  game::Initialize();

  while (!renderer::IsWindowClosing()) {
	game::Update();
	renderer::Update();
  }

  game::Terminate();
  renderer::Terminate();
}

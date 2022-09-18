#include "Engine.h"
#include "../renderer/Provider.h"
#include "../game/Initializer.h"

std::vector<GameObject *> engine::gameObjects{};

bool engine::Initialize() {
  return Initializer::Initialize();
}

void engine::Update() {

  for (GameObject *game_object : engine::gameObjects) {
	game_object->Update();
  }
}

void engine::Terminate() {

  for (GameObject *game_object : engine::gameObjects) {
	delete game_object;
  }

  gameObjects.clear();
}

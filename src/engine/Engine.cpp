#include "Engine.h"

std::vector<GameObject*> Engine::gameObjects{};

void Engine::Update() {

	for (GameObject* gameObject : Engine::gameObjects) {
		gameObject->Update();
	}
}

void Engine::Terminate() {
	gameObjects.clear();
}
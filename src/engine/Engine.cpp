#include "Engine.h"

std::vector<GameObject*> engine::gameObjects{};

void engine::Update() {

	for (GameObject* gameObject : engine::gameObjects) {
		gameObject->Update();
	}
}

void engine::Terminate() {
	gameObjects.clear();
}
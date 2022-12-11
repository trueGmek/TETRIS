#include "Engine.h"
#include "../renderer/Provider.h"
#include "../game/Initializer.h"
#include "Input.h"

std::vector<GameObject*> engine::gameObjects{};

bool engine::Initialize() {
	bool result = false;
	result |= Input::Initialize();
	result |= Initializer::Initialize();
	return result;
}

void engine::Update() {

	for (GameObject* gameObject : engine::gameObjects) {
		gameObject->Update();
	}
}

void engine::Terminate() {

	for (GameObject* gameObject : engine::gameObjects) {
		delete gameObject;
	}

	gameObjects.clear();
}
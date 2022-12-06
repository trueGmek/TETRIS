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

	for (GameObject* game_object : engine::gameObjects) {
		game_object->Update();
	}
}

void engine::Terminate() {

	for (GameObject* game_object : engine::gameObjects) {
		delete game_object;
	}

	gameObjects.clear();
}

void engine::StartGameObjects() {

	for (GameObject* game_object : engine::gameObjects) {
		game_object->Start();
	}
}

void engine::EnableGameObjects() {
	for (GameObject* game_object : engine::gameObjects) {
		game_object->OnEnable();
	}
}

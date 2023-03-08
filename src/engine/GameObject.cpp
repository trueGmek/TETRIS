#include "GameObject.h"
#include "Engine.h"

GameObject::GameObject() {
	Engine::gameObjects.insert(Engine::gameObjects.begin(), this);
}

GameObject::~GameObject() {
	std::remove(Engine::gameObjects.begin(), Engine::gameObjects.end(), this);
}

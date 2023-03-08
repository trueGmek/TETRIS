#include "GameObject.h"

#include "Engine.h"

GameObject::GameObject() {
	engine::gameObjects.insert(engine::gameObjects.begin(), this);
}

GameObject::~GameObject() {
	std::remove(engine::gameObjects.begin(), engine::gameObjects.end(), this);
}
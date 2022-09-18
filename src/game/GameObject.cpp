#include "GameObject.h"

#include "../engine/Engine.h"

GameObject::GameObject() {
  engine::gameObjects.insert(engine::gameObjects.begin(), this);
}

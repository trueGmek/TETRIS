#pragma once

#include <vector>
#include "GameObject.h"

namespace Engine
{
	extern std::vector<GameObject*> gameObjects;

	void Update();
	void Terminate();
}

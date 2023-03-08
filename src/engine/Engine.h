#ifndef TETRIS_SRC_ENGINE_ENGINE_H_
#define TETRIS_SRC_ENGINE_ENGINE_H_

#include <vector>
#include "GameObject.h"

namespace engine
{
	extern std::vector<GameObject*> gameObjects;

	void Update();
	void Terminate();

}

#endif //TETRIS_SRC_ENGINE_ENGINE_H_

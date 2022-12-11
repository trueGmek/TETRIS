#ifndef TETRIS_SRC_ENGINE_ENGINE_H_
#define TETRIS_SRC_ENGINE_ENGINE_H_

#include <vector>
#include "../renderer/primitives/cube/Cube.h"
#include "../game/GameObject.h"

namespace engine
{

	extern std::vector<GameObject*> gameObjects;

	bool Initialize();
	void Update();
	void Terminate();

}

#endif //TETRIS_SRC_ENGINE_ENGINE_H_

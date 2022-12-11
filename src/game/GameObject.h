#ifndef TETRIS_SRC_GAME_GAMEOBJECT_H
#define TETRIS_SRC_GAME_GAMEOBJECT_H

#include "../Transform.h"

class GameObject
{
public:
	Transform transform{};

	GameObject();

	virtual ~GameObject() = default;

	virtual void Update() = 0;
};

#endif //TETRIS_SRC_GAME_GAMEOBJECT_H

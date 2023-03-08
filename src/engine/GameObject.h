#ifndef TETRIS_SRC_GAME_GAMEOBJECT_H
#define TETRIS_SRC_GAME_GAMEOBJECT_H

#include "Transform.h"

class GameObject
{
public:
	Transform transform{};

	GameObject();

	~GameObject();

	virtual void Update() = 0;
};

#endif //TETRIS_SRC_GAME_GAMEOBJECT_H

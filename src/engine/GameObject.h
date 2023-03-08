#pragma once

#include "Transform.h"

class GameObject
{
public:
	Transform transform{};

	GameObject();

	~GameObject();

	virtual void Update() = 0;
};

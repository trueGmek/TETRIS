#pragma once

#include "Material.h"

struct LineMaterial : Material
{
public :
	float Width{};
	LineMaterial() = default;
};

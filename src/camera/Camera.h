#pragma once

//zastąpić folder osobnymi bibliotekami
//osobny CMAKEList na każdy folder
//i buduje osobną biblotekę
#include "../Transform.h"
//bez tego konstruktora można zmienić klasę na namespace
class Camera
{
public:
//ten konstruktor jest niepotrzebny
	Camera();

//Wyrażenie czasownikowe
	static glm::mat4 ProjectionMatrix();
	static glm::mat4 ViewMatrix();
	static glm::mat4 ScreenToWorld();
};

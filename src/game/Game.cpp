#include "Game.h"
#include "glm/vec3.hpp"
#include "../renderer/Renderer.h"

Renderer::Cube* cube1;
Renderer::Cube* cube2;
Renderer::Cube* cube3;
Renderer::Cube* cube4;

bool Game::Initialize()
{

	cube1 = new Renderer::Cube();
	cube2 = new Renderer::Cube();
	cube3 = new Renderer::Cube();
	cube4 = new Renderer::Cube();

	return true;
}

void Game::Update()
{
	Transform transform1, transform2, transform3, transform4;
	Material material1, material2, material3, material4;

	material1.Color = glm::vec4{ 1, 0, 0, 1 };
	material2.Color = glm::vec4{ 0, 1, 0, 1 };
	material3.Color = glm::vec4{ 0, 0, 1, 1 };
	material4.Color = glm::vec4{ 0, 1, 1, 1 };

	transform1.Position = glm::vec3{ -1.5, 0, -1 };
	transform2.Position = glm::vec3{ 0.5, 0, -1 };
	transform3.Position = glm::vec3{ 0, 0.5, -1 };
	transform4.Position = glm::vec3{ 0, -0.5, -1 };

	cube1->SetTransform(transform1);
	cube1->SetMaterial(material1);

	cube2->SetTransform(transform2);
	cube2->SetMaterial(material2);

	cube3->SetTransform(transform3);
	cube3->SetMaterial(material3);

	cube4->SetTransform(transform4);
	cube4->SetMaterial(material4);

	Renderer::_primitivesQueue.push(cube1);
	Renderer::_primitivesQueue.push(cube2);
	Renderer::_primitivesQueue.push(cube3);
	Renderer::_primitivesQueue.push(cube4);
}

void Game::Terminate()
{

}

#include "renderer/Renderer.h"

int main()
{
	Renderer::Initialize();

	while (!Renderer::IsWindowClosing())
	{
		Renderer::Update();
	}

	Renderer::Terminate();
}

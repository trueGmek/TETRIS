#pragma  once

#include "shader/Shader.h"
#include "Material.h"

namespace Renderer
{
	class Primitive
	{
	public:
		virtual void Bind() = 0;

		virtual void Unbind() = 0;

		virtual void SetData() = 0;

		virtual void Draw() = 0;
	};

} // Renderer

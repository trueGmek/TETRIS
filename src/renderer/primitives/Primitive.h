#ifndef TETRIS_SRC_RENDERER_PRIMITIVES_PRIMITIVE_H_
#define TETRIS_SRC_RENDERER_PRIMITIVES_PRIMITIVE_H_

#include "../shader/Shader.h"
#include "../Material.h"
#include "../../Transform.h"

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

#endif //TETRIS_SRC_RENDERER_PRIMITIVES_PRIMITIVE_H_

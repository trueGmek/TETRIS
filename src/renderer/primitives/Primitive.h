#ifndef TETRIS_SRC_RENDERER_PRIMITIVES_PRIMITIVE_H
#define TETRIS_SRC_RENDERER_PRIMITIVES_PRIMITIVE_H

#include "../shader/Shader.h"
#include "../Material.h"
#include "../../Transform.h"

namespace Renderer
{

	class Primitive
	{
	protected:
		Shader* _shader;
		Material _material;
		Transform _transform;

		unsigned int _vbo;
		unsigned int _vao;
		unsigned int _ebo;

	public:
		virtual void Bind()
		{
			glBindVertexArray(_vao);
			_shader->Use();
		}

		virtual void Unbind()
		{
			glBindVertexArray(0);
		}

		virtual void SetData() = 0;

		virtual void Draw() = 0;
	};

} // Renderer

#endif //TETRIS_SRC_RENDERER_PRIMITIVES_PRIMITIVE_H

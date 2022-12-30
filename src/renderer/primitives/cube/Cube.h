#ifndef TETRIS_SRC_RENDERER_PRIMITIVES_CUBE_CUBE_H
#define TETRIS_SRC_RENDERER_PRIMITIVES_CUBE_CUBE_H

#include "../Primitive.h"
#include "../../../Transform.h"
#include "../../../camera/Camera.h"

namespace Renderer
{
	class Cube : public Primitive
	{
	public:
		Transform MyTransform;
		Material MyMaterial;
	private:
		Shader* _shader{};

		unsigned int _vbo{};
		unsigned int _vao{};
		unsigned int _ebo{};
		unsigned int _texture{};

	public:
		Cube();
		~Cube();

		void Bind() override;
		void Draw() override;
		void Unbind() override;
		void SetData() override;
	};

} // Renderer

#endif //TETRIS_SRC_RENDERER_PRIMITIVES_CUBE_CUBE_H

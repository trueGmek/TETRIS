#ifndef TETRIS_SRC_RENDERER_PRIMITIVES_CUBE_CUBE_H_
#define TETRIS_SRC_RENDERER_PRIMITIVES_CUBE_CUBE_H_

#include "../Primitive.h"
#include "../../../Transform.h"//;
#include "../../../camera/Camera.h"

namespace renderer
{

	class Cube : public Primitive
	{
	public:
		Transform transform_;
		Material material_;
	private:
		Shader* shader_{};

		unsigned int vbo_{};
		unsigned int vao_{};
		unsigned int ebo_{};

	public:
		Cube();
		~Cube();

		void Bind() override;
		void Draw() override;
		void Unbind() override;
		void SetData() override;

		void SetTransform(const Transform& transform);
	};

} // Renderer

#endif //TETRIS_SRC_RENDERER_PRIMITIVES_CUBE_CUBE_H_

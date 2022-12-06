#ifndef TETRIS_SRC_RENDERER_PRIMITIVES_LINE_LINE_H_
#define TETRIS_SRC_RENDERER_PRIMITIVES_LINE_LINE_H_

#include "../Primitive.h"
#include "LineMaterial.h"

namespace renderer
{

	class Line : public renderer::Primitive
	{
	public:

		LineMaterial material_{};
	private:

		unsigned int vbo_{};
		unsigned int vao_{};

		Shader* shader_;

	public:
		Transform start_{};
		Transform end_{};
		Transform pivot_{};

		Line();
		Line(Transform start, Transform end, Transform pivot, LineMaterial line_material);
		Line(Line&& line) noexcept;
		Line& operator=(Line&& a) noexcept;
		~Line();

		void Bind() override;
		void Draw() override;
		void Unbind() override;
		void SetData() override;

		void SetStart(const Transform& transform);
		void SetEnd(const Transform& transform);
		void SetPivot(const Transform& transform);
	};

} // Renderer

#endif //TETRIS_SRC_RENDERER_PRIMITIVES_LINE_LINE_H_

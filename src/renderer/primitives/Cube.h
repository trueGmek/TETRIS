#ifndef TETRIS_SRC_RENDERER_PRIMITIVES_CUBE_H
#define TETRIS_SRC_RENDERER_PRIMITIVES_CUBE_H

#include "Primitive.h"
#include "../../Transform.h"//;
#include "../Primitives.h"
#include "../../camera/Camera.h"

namespace Renderer
{

	class Cube : public Primitive
	{
	private:

	public:
		Cube();

		void SetData() override;
		void Draw() override;
	
		void SetTransform(const Transform& transform);
		void SetMaterial(const Material& material);
	};

} // Renderer

#endif //TETRIS_SRC_RENDERER_PRIMITIVES_CUBE_H

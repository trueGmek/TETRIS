//
// Created by gmek on 2/8/23.
//

#ifndef TETRIS_SRC_RENDERER_PRIMITIVES_TEXTPRIMITIVE_H
#define TETRIS_SRC_RENDERER_PRIMITIVES_TEXTPRIMITIVE_H

#include "Primitive.h"

namespace Renderer
{

	class TextPrimitive : public Primitive
	{
	public:
		Transform MyTransform;
		Material MyMaterial;
		std::string Text;

	private:
		Shader* _shader;
		unsigned int _vbo{};
		unsigned int _vao{};


	public:
		TextPrimitive();
		~TextPrimitive();

		void Bind() override;
		void Draw() override;
		void Unbind() override;
		void SetData() override;
	};

} // Renderer

#endif //TETRIS_SRC_RENDERER_PRIMITIVES_TEXTPRIMITIVE_H

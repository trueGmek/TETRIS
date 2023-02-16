
#ifndef TETRIS_SRC_RENDERER_CHARACTER_H
#define TETRIS_SRC_RENDERER_CHARACTER_H

#include "glm/ext/vector_int2.hpp"

namespace Renderer
{
	struct Character
	{
		unsigned int TextureID;
		glm::ivec2 Size;
		glm::ivec2 Bearing; //Offset from baseline to left/top of the glyph
		unsigned int Advance;
	};
}

#endif //TETRIS_SRC_RENDERER_CHARACTER_H

#ifndef TETRIS_SRC_RENDERER_TEXT_H
#define TETRIS_SRC_RENDERER_TEXT_H

#include <iostream>
#include <map>
#include "ft2build.h"
#include FT_FREETYPE_H
#include "Character.h"

namespace Renderer::Text
{
	extern std::map<char, Renderer::Character> Characters;

	bool Initialize(std::string const& path);
	bool Deinitialize();
	FT_GlyphSlot GetGlyph(char character);
};

#endif //TETRIS_SRC_RENDERER_TEXT_H

#include "Text.h"

namespace Renderer::Text
{
	FT_Library library;
	FT_Face face;

	std::map<char, Renderer::Character> Characters{};

	const std::string tag{ "Renderer::Text" };

	bool Initialize(std::string const& path) {
		auto error = FT_Init_FreeType(&library);
		if (error) {
			std::cout << tag << "Initialize: An error has occurred" << std::endl;
			return false;
		}

		error = FT_New_Face(library, path.c_str(), 0, &face);
		if (error == FT_Err_Unknown_File_Format) {
			std::cout << tag << "::Initialize: Unsupported file format" << std::endl;
			return false;
		}
		else if (error) {
			std::cout << tag << "::Initialize: Unknown error while loading font face" << std::endl;
			return false;
		}

		error = FT_Set_Pixel_Sizes(face, 0, 48);
		if (error) {
			std::cout << tag << "::Initialize: Error while setting char size" << std::endl;
			return false;
		}

		return true;
	}

	FT_GlyphSlot GetGlyph(char character) {

		FT_Error error;

		error = FT_Load_Char(face, character, FT_LOAD_RENDER);

		if (error) {
			std::cout << tag << "::GetGlyph: Error while loading the character" << std::endl;
			return nullptr;
		}

		return face->glyph;
	}

	bool Deinitialize() {
		FT_Done_Face(face);
		FT_Done_FreeType(library);
		return true;
	}

}
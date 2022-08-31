#ifndef TETRIS_SRC_DEBUG_DEBUG_H
#define TETRIS_SRC_DEBUG_DEBUG_H

#include <ostream>
#include "glm/ext/matrix_float4x4.hpp"

namespace Debug
{
	std::ostream& operator<<(std::ostream& out, const glm::mat4& matrix)
	{
		out << "";
		return out;
	}

	std::string Print(glm::mat4 mat)
	{
		std::string value;

		for (int j = 0; j < 4; ++j)
		{
			for (int i = 0; i < 4; ++i)
			{
				value.append("[").append(std::to_string(mat[j][i])).append("]");
			}
			value.append("\n");
		}

		return value;
	}

}

#endif //TETRIS_SRC_DEBUG_DEBUG_H

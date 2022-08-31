#ifndef TETRIS_SRC_RENDERER_PRIMITIVES_H
#define TETRIS_SRC_RENDERER_PRIMITIVES_H

namespace Primitives
{
	float const CubeVertices[] = {
		-0.5f, 0.5, 0.0,    //TOP LEFT
		0.5f, 0.5f, 0.0f,   // TOP RIGHT
		-0.5f, -0.5f, 0.05, // BOTTOM LEFT
		0.5f, -0.5f, 0.05 //BOTTOM RIGHT
	};

	unsigned int const CubeIndices[] = {
		0, 2, 3,
		0, 1, 3
	};
	
	

}

#endif //TETRIS_SRC_RENDERER_PRIMITIVES_H

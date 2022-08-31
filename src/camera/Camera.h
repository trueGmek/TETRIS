#ifndef TETRIS_SRC_CAMERA_CAMERA_H
#define TETRIS_SRC_CAMERA_CAMERA_H

#include "../Transform.h"

class Camera
{
public:
	Camera();
	static glm::mat4 GetProjectionMatrix();

private:
};

#endif //TETRIS_SRC_CAMERA_CAMERA_H

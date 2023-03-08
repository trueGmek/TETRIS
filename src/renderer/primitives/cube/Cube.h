#pragma once

#include "primitives/Primitive.h"
#include "camera/Camera.h"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/quaternion_float.hpp"

namespace Renderer
{
	class Cube : public Primitive
	{
	public:
		glm::vec3 Position{ 0.0f, 0.0f, 0.0f };
		glm::quat Rotation{ 1.0f, 0.0f, 0.0f, 0.0f };
		glm::vec3 Scale{ 1, 1, 1 };

		Material MyMaterial;
	private:
		Shader* _shader;

		unsigned int _vbo{};
		unsigned int _vao{};
		unsigned int _ebo{};
		unsigned int _texture{};

	public:
		Cube();
		~Cube();

		void Bind() override;
		void Draw() override;
		void Unbind() override;
		void SetData() override;
	};

} // Renderer

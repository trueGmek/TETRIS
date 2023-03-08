#pragma once

#include "Primitive.h"
#include "glm/vec3.hpp"
#include "glm/gtc/quaternion.hpp"

namespace Renderer
{

	class TextPrimitive : public Primitive
	{
	public:
		glm::vec3 Position{ 0.0f, 0.0f, 0.0f };
		glm::quat Rotation{ 1.0f, 0.0f, 0.0f, 0.0f };
		glm::vec3 Scale{ 1, 1, 1 };

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

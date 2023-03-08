#pragma  once

#include "primitives/Primitive.h"
#include "LineMaterial.h"
#include "glm/vec3.hpp"

namespace Renderer
{
	class Line : public Renderer::Primitive
	{
	public:
		LineMaterial Material{};
		glm::vec3 Start{};
		glm::vec3 End{};
		glm::vec3 Position{ 0.0f, 0.0f, 0.0f };
		glm::vec3 Scale{ 1, 1, 1 };
	private:
		unsigned int _vbo{};
		unsigned int _vao{};
		Shader* _shader;
	public:

		Line();
		~Line();

		void Bind() override;
		void Draw() override;
		void Unbind() override;
		void SetData() override;
	};

} // Renderer

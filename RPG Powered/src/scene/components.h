#pragma once

#include <glm/glm.hpp>

namespace Engine {

	struct TransformComponent {
		glm::vec3 position{ 1.0f };

		TransformComponent() = default;
		TransformComponent(const TransformComponent&) = default;
		TransformComponent(const glm::vec3&pos) : position(pos){}
	};

	struct SpriteRendererComponent {
		glm::vec4 Color{ 255.0f, 255.0f, 255.0f, 255.0f };

		SpriteRendererComponent() = default;
		SpriteRendererComponent(const SpriteRendererComponent&) = default;
		SpriteRendererComponent(const glm::vec4& color) : Color(color) {}
	};

}

#pragma once

#include <glm/glm.hpp>
#include <string>

#include "../Camera.h"

namespace Engine {

	struct TagComponent {
		std::string Tag;

		TagComponent() = default;
		TagComponent(const TagComponent&) = default;
		TagComponent(const std::string& tag) : Tag(tag) {}
	};

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

	struct CameraComponent {
		Camera camera;
		bool Primary = true;

		CameraComponent() = default;
		CameraComponent(const CameraComponent&) = default;
		CameraComponent(const SDL_Rect& dim) : camera(dim) {}
	};

}

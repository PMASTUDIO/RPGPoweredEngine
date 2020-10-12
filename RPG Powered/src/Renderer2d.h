#pragma once

#include <glm/glm.hpp>
#include "core.h"

namespace Engine {

	class Camera;

	class Renderer2D {
	public:
		static void BeginScene(SDL_Renderer* renderer);

		static void DrawQuad(SDL_Renderer *renderer, Camera& camera, glm::vec3& pos, glm::vec2& dimensions, const glm::vec4& color);
		static void DrawSquare(SDL_Renderer* renderer, Camera& camera, glm::vec3& pos, const glm::vec4& color);

		static void DrawQuad(SDL_Renderer* renderer, Camera& camera, const glm::vec2& pos, const glm::vec2& size, SDL_Texture& texture);
		static void DrawQuad(SDL_Renderer* renderer, Camera& camera, const glm::vec2& pos, const glm::vec2& size, const Rect& source, SDL_Texture& texture);

		static void EndScene(SDL_Renderer* renderer);
	};
}
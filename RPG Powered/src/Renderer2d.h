#pragma once

#include <glm/glm.hpp>
#include "core.h"

namespace Engine {
	class Renderer2D {
	public:
		static void BeginScene(SDL_Renderer* renderer);
		static void DrawQuad(SDL_Renderer *renderer, glm::vec3& pos, const glm::vec4& color);
		static void EndScene(SDL_Renderer* renderer);
	};
}
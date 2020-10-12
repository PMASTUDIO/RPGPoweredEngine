#pragma once

#include <glm/glm.hpp>
#include "core.h"

namespace Engine {
	class Renderer2D {
	public:
		static void DrawQuad(SDL_Renderer *renderer, glm::vec3& pos, const glm::vec4& color);
	};
}
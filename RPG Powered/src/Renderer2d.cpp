#include "Renderer2d.h"

void Engine::Renderer2D::DrawQuad(SDL_Renderer* renderer, glm::vec3& pos, const glm::vec4& color)
{
	Rect quad = {
		pos.x,
		pos.y,
		100,
		100
	};

	SET_RENDER_DRAW_COLOR(renderer, color.x, color.y, color.z, color.w);
	FILL_RECT(renderer, &quad);
}

#include "Renderer2d.h"
#include "managers/TextureManager.h"

void Engine::Renderer2D::BeginScene(SDL_Renderer* renderer)
{
	SET_RENDER_DRAW_COLOR(renderer, 0, 0, 0, 255);
	CLEAR_RENDERER(renderer);
}

void Engine::Renderer2D::DrawQuad(SDL_Renderer* renderer, glm::vec3& pos, glm::vec2& dimensions, const glm::vec4& color)
{
	Rect quad = {
		pos.x,
		pos.y,
		dimensions.x,
		dimensions.y
	};

	SET_RENDER_DRAW_COLOR(renderer, color.x, color.y, color.z, color.w);
	FILL_RECT(renderer, &quad);
}

void Engine::Renderer2D::DrawSquare(SDL_Renderer* renderer, glm::vec3& pos, const glm::vec4& color)
{
	glm::vec2 Dimensions{ 100.0f, 100.0f };
	DrawQuad(renderer, pos, Dimensions, color);
}

void Engine::Renderer2D::DrawQuad(SDL_Renderer* renderer, const glm::vec2& pos, const glm::vec2& size, std::string path)
{
	auto texture = TextureManager::LoadTexture(renderer, path);
	Engine::TextureManager::Draw(renderer, texture, Rect{ (int)pos.x, (int)pos.y, (int)size.x, (int)size.y });
}

void Engine::Renderer2D::DrawQuad(SDL_Renderer* renderer, const glm::vec2& pos, const glm::vec2& size, const Rect& source, std::string path)
{
	auto texture = TextureManager::LoadTexture(renderer, path);
	Engine::TextureManager::Draw(renderer, texture, source, Rect{ (int)pos.x, (int)pos.y, (int)size.x, (int)size.y });
}

void Engine::Renderer2D::EndScene(SDL_Renderer* renderer)
{
	PRESENT(renderer);
}

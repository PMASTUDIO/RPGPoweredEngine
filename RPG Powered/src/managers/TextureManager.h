#pragma once

#include <SDL.h>
#include <string>

namespace Engine {
	class TextureManager {
	public:
		static SDL_Texture* LoadTexture(SDL_Renderer* renderer, std::string filename);
		static void Draw(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect sourceRect, SDL_Rect destinationRect, SDL_RendererFlip flip = SDL_FLIP_NONE);
		static void Draw(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect destinationRect, SDL_RendererFlip flip = SDL_FLIP_NONE);
	};
}
#include "TextureManager.h"
#include <SDL_image.h>

SDL_Texture* Engine::TextureManager::LoadTexture(SDL_Renderer* renderer, std::string filename)
{
    SDL_Surface* surface = IMG_Load(filename.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void Engine::TextureManager::Draw(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect sourceRect, SDL_Rect destinationRect, SDL_RendererFlip flip)
{
    SDL_RenderCopyEx(renderer, texture, &sourceRect, &destinationRect, NULL, NULL, flip);
}

void Engine::TextureManager::Draw(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect destinationRect, SDL_RendererFlip flip)
{
    SDL_RenderCopyEx(renderer, texture, NULL, &destinationRect, NULL, NULL, flip);
}

#pragma once

#include <SDL.h>

namespace Engine {
	class Camera {
	public:
		Camera(const SDL_Rect &dim) : m_Dimensions(dim){}

		SDL_Rect& GetDimensions() { return m_Dimensions; }
		void SetDimensions(const SDL_Rect& dim) { m_Dimensions = dim; }
	private:
		SDL_Rect m_Dimensions;
	};
}
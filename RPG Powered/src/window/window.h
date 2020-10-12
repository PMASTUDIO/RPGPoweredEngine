#pragma once

#include <string>

#include "../core.h"
#include <SDL.h>

namespace Engine{

	using Renderer = SDL_Renderer;

	class Window
	{
	public:
		Window();
		~Window();

		void InitRenderer(std::string title, int width = 1280, int height = 720, bool fullscreen = false);
			
		Renderer* GetRenderer() { return m_renderer; };

		void Destroy();

	private:
		bool Init();
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
	};

}

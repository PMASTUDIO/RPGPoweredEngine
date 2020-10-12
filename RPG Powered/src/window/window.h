#pragma once

#include <memory>
#include <string>

#include "../core.h"
#include <SDL.h>

namespace Engine{

	class Window
	{
	public:
		Window(std::string title, int width = 1280, int height = 720, bool fullscreen = false);
		~Window();

	private:
		bool Init();
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
	};

	Window::Window(std::string title, int width, int height, bool fullscreen)
	{
		Init();
		Uint32 flags = 0;
		if (fullscreen)
			flags = SDL_WINDOW_FULLSCREEN;

		m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		if (!m_window)
			LOG_ERROR("Error initializing SDL Window \n");

		SDL_Renderer* renderer = SDL_CreateRenderer(m_window, -1, 0);
		if(!renderer)
			LOG_ERROR("Error initializing SDL Renderer \n");
	}

	Window::~Window()
	{ 
		SDL_DestroyWindow(m_window);
	}

	inline bool Window::Init()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			LOG_ERROR("Error initializing SDL")
				return false;
		}

		return true;
	}

}

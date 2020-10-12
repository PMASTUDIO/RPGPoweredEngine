#include "window.h"
#include <SDL_image.h>

namespace Engine {
	Window::Window() : m_renderer(nullptr), m_window(nullptr)
	{
		
	}

	Window::~Window()
	{
		
	}

	void Window::InitRenderer(std::string title, int width, int height, bool fullscreen)
	{
		if (!Init())
			return;

		Uint32 flags = SDL_WINDOW_SHOWN;
		if (fullscreen)
			flags = SDL_WINDOW_FULLSCREEN;

		m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		if (!m_window)
			LOG_ERROR("Error initializing SDL Window \n");

		m_renderer = SDL_CreateRenderer(m_window, -1, 0);
		if (!m_renderer)
			LOG_ERROR("Error initializing SDL Renderer \n");

		if (!IMG_Init(IMG_INIT_JPG))
			LOG_ERROR("Error initializing SDL Image for jpg! \n");
		
	}

	void Window::Destroy()
	{
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}

	bool Window::Init()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			LOG_ERROR("Error initializing SDL")
			return false;
		}

		return true;
	}
}
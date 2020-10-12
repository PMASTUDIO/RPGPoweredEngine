#include "Game.h"
#include "core.h"

Game::Game() : m_isRunning(true)
{
	m_Window = std::make_unique<Engine::Window>();
}

Game::~Game()
{
}

void Game::Init()
{
	m_Window->InitRenderer("My RPG Game!!!");
}

void Game::ProcessInput()
{
	Engine_Event evt;

	while (EVENT_POLL(&evt)) {
		switch (evt.type) {
		case EVT_QUIT:
			m_isRunning = false;
			break;
		}
	}
}

void Game::Update()
{
}

void Game::Render()
{
	SET_RENDER_DRAW_COLOR(m_Window->GetRenderer(), 0, 0, 0, 255);
	CLEAR_RENDERER(m_Window->GetRenderer());

	// Draw and render objects
	Rect square = {
		100,
		100,
		100,
		100
	};

	SET_RENDER_DRAW_COLOR(m_Window->GetRenderer(), 255, 0, 0, 255);
	FILL_RECT(m_Window->GetRenderer(), &square)

	PRESENT(m_Window->GetRenderer());

}

void Game::Destroy()
{
	m_Window->Destroy();
}

#include "Game.h"
#include "core.h"
#include "scene/components.h"

#include "Renderer2d.h"

Game::Game() : m_isRunning(true), m_ticksCount(0)
{
	m_Window = std::make_unique<Engine::Window>();
	m_ActiveScene = std::make_unique<Engine::Scene>();
}

Game::~Game()
{
}

void Game::Init()
{
	m_Window->InitRenderer("My RPG Game!!!");

	auto square = m_ActiveScene->CreateEntity();
	m_ActiveScene->Reg().emplace<Engine::TransformComponent>(square);
	m_ActiveScene->Reg().emplace<Engine::SpriteRendererComponent>(square, glm::vec4{ 0.0f, 255.0f, 0.0f, 255.0f });
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
	float deltaTime = (SDL_GetTicks() - m_ticksCount) / 1000.0f;
	m_ticksCount = SDL_GetTicks();

	if (deltaTime > 0.05f) {
		deltaTime = 0.05f;
	}

	// UPDATE GAME OBJECTS
	
}

void Game::Render()
{
	SET_RENDER_DRAW_COLOR(m_Window->GetRenderer(), 0, 0, 0, 255);
	CLEAR_RENDERER(m_Window->GetRenderer());

	// Draw and render objects
	m_ActiveScene->OnUpdate(m_Window->GetRenderer(), 0.0f);

	PRESENT(m_Window->GetRenderer());

}

void Game::Destroy()
{
	m_Window->Destroy();
}

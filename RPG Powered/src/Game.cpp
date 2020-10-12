#include "Game.h"
#include "core.h"
#include "scene/components.h"

#include "Renderer2d.h"

Game::Game() : m_isRunning(true), m_ticksCount(0)
{
	m_Window = std::make_unique<Engine::Window>();
}

Game::~Game()
{
}

void Game::Init()
{
	m_Window->InitRenderer("My RPG Game!!!");
	m_ActiveScene = std::make_shared<Engine::Scene>();
	
	auto square = m_ActiveScene->CreateEntity("Green square");
	
	if(square)
		square.AddComponent<Engine::SpriteRendererComponent>(glm::vec4{ 0.0f, 255.0f, 0.0f, 255.0f });

	auto blueSquare = m_ActiveScene->CreateEntity("Blue square");

	m_SquareEntity = square;
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
	Engine::Renderer2D::BeginScene(m_Window->GetRenderer());

	// DRAW GAME OBJECTS
	/*Engine::Renderer2D::DrawQuad(m_Window->GetRenderer(), { 50.0f, 50.0f },  { 200.0f, 200.0f }, "test_assets/box.jpg");
	Engine::Renderer2D::DrawQuad(m_Window->GetRenderer(), { 200.0f, 200.0f }, { 200.0f, 200.0f }, {20, 20, 100, 100}, "test_assets/box.jpg");*/

	m_ActiveScene->OnUpdate(m_Window->GetRenderer(), deltaTime);

	Engine::Renderer2D::EndScene(m_Window->GetRenderer());
}

void Game::Destroy()
{
	m_Window->Destroy();
}

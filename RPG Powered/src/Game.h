#pragma once

#include <memory>
#include "window/window.h"
#include "scene/scene.h"
#include "scene/entity.h"

class Game {
public:
	Game();
	~Game();

	void Init();

	bool IsRunning() const { return m_isRunning; }
	void ProcessInput();
	void Update();
	void Destroy();
private:
	bool m_isRunning;
	std::unique_ptr<Engine::Window> m_Window;
	std::shared_ptr<Engine::Scene> m_ActiveScene;

	Uint32 m_ticksCount;

	Engine::Entity m_SquareEntity;
	Engine::Entity m_CameraEntity;

	SDL_Texture* m_BoxTexture;
};

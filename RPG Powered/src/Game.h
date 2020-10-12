#pragma once

#include <memory>
#include "window/window.h"
#include "scene/scene.h"

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
	std::unique_ptr<Engine::Scene> m_ActiveScene;

	Uint32 m_ticksCount;
};

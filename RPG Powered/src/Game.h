#pragma once

#include <memory>
#include "window/window.h"

class Game {
public:
	Game();
	~Game();

	void Init();

	bool IsRunning() const { return m_isRunning; }
	void ProcessInput();
	void Update();
	void Render();
	void Destroy();
private:
	bool m_isRunning;
	std::unique_ptr<Engine::Window> m_Window;
};

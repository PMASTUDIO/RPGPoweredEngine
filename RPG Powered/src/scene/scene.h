#pragma once

#include <SDL.h>
#include <entt/entt.hpp>
#include "components.h"

namespace Engine {
	class Scene {
	public:
		Scene();
		~Scene();

		entt::entity CreateEntity();

		entt::registry& Reg() { return m_Registry; }

		void OnUpdate(SDL_Renderer* renderer, float dt);

	private:
		entt::registry m_Registry;
	};
}

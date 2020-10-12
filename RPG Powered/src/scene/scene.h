 #pragma once

#include <SDL.h>
#include <entt/entt.hpp>
#include "components.h"

namespace Engine {

	class Entity;

	class Scene {
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = std::string());

		void OnUpdate(SDL_Renderer* renderer, float dt);

	private:
		entt::registry m_Registry;

		friend class Entity;
	};
}

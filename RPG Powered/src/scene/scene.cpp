#include "scene.h"
#include "../Renderer2d.h"

Engine::Scene::Scene()
{

}

Engine::Scene::~Scene()
{
}

entt::entity Engine::Scene::CreateEntity()
{
	return m_Registry.create();
}

void Engine::Scene::OnUpdate(SDL_Renderer* renderer, float dt)
{
	auto group = m_Registry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
	for (auto entity : group) {
		
		auto[transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);

		Renderer2D::DrawQuad(renderer, transform.position, sprite.Color);
	}
}

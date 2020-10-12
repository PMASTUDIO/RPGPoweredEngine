#include "scene.h"
#include "../Renderer2d.h"

#include "entity.h"

Engine::Scene::Scene()
{

}

Engine::Scene::~Scene()
{
}

Engine::Entity Engine::Scene::CreateEntity(const std::string& name)
{
	Entity e = { m_Registry.create(), this };

	e.AddComponent<TransformComponent>();
	auto& tag = e.AddComponent<TagComponent>();
	tag.Tag = name.empty() ? "Unnamed Entity" : name;

	return e;
}

void Engine::Scene::OnUpdate(SDL_Renderer* renderer, float dt)
{
	auto group = m_Registry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
	for (auto entity : group) {
		
		auto[transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);

		Renderer2D::DrawSquare(renderer, transform.position, sprite.Color);
	}
}

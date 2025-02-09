#include "RenderSystem.hpp"

void RenderSystem::update(EntityManager& em, float Deltatime)
{
	em.forEach<CmpsList, TagList>([&](Entity& e,RenderComponent& rc)
	{
		//Update rotation
		float angle = rc.angle * static_cast<float>(Deltatime);
		rc.model->setRotation(glm::angleAxis(glm::radians(angle), glm::vec3(0, 1, 0)));
		//update position
		//rc.model->setPosition(glm::vec3(0.f, 0.f, 0.f));
		//Draw
		rc.model->draw();
	});
}

void RenderSystem::Init()
{
	//cargar modelos
}

void RenderSystem::UnloadModels(EntityManager& em)
{
	em.forEach<CmpsList, TagList>([&](Entity& e, RenderComponent& rc)
	{
		delete rc.model;
		rc.model = nullptr;
	});
}

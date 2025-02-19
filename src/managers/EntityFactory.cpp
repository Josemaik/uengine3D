#include "EntityFactory.hpp"

void EntityFactory::CreateTriangles(EntityManager& em)
{
	////Creamos 9 triángulos
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			auto& triangle = em.createEntity();
			em.addTag<triangleTag>(triangle);
			auto& r = em.addComponent<RenderComponent>(triangle);
			r.position = glm::vec3(col * 3.f - 3.f, 0.0f, -row * 3.0f);
		}
	}
}

void EntityFactory::CreateCube(EntityManager& em)
{
	//Creamos cubo
	auto& cube{ em.createEntity() };
	em.addTag<boxTag>(cube);
	auto& r = em.addComponent<RenderComponent>(cube);
	r.position = glm::vec3(0.f, 0.f, 0.f);
}

void EntityFactory::CreateBoxStack(EntityManager& em)
{
	//Creamos box stack
	auto& boxstack{ em.createEntity() };
	em.addTag<boxStackTag>(boxstack);
	auto& r = em.addComponent<RenderComponent>(boxstack);
	r.position = glm::vec3(0.f, -20.f, 0.f);
	r.scale = glm::vec3(4.f, 4.f, 4.f);
}

void EntityFactory::CreateGunSlinger(EntityManager& em)
{
	//Creamos gunslinger
	auto& gunslinger{ em.createEntity() };
	em.addTag<gunslingerTag>(gunslinger);
	auto& r = em.addComponent<RenderComponent>(gunslinger);
	r.position = glm::vec3(0.f, 0.f, 0.f);
	r.scale = glm::vec3(0.5f, 0.5f, 0.5f);
}

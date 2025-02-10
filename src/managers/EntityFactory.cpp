#include "EntityFactory.hpp"

void EntityFactory::CreateTriangles(EntityManager& em)
{
	//Creamos 9 triángulos
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			auto& triangle = em.createEntity();
			auto& r = em.addComponent<RenderComponent>(triangle);
			r.position = glm::vec3(col * 3.f - 3.f, 0.0f, -row * 3.0f);
			//r.model = new Model(mesh); //engine.LoadModel()
			//r.model->setPosition(glm::vec3(col * 3.f - 3.f, 0.0f, -row * 3.0f));
			//r.model->setScale(glm::vec3(1.f, 1.f, 1.f));
		}
	}
}

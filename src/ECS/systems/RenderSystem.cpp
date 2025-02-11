#include "RenderSystem.hpp"

#include "../../managers/GameEngine.hpp"

void RenderSystem::update(EntityManager& em, float Deltatime)
{
	em.forEach<CmpsList, TagList>([&](Entity& e,RenderComponent& rc)
	{
		//Update rotation
		float angle = rc.angle * static_cast<float>(Deltatime);
		rc.model->setRotation(glm::angleAxis(glm::radians(angle), glm::vec3(0, 1, 0)));
		//Draw
		rc.model->draw();
	});
}

void RenderSystem::LoadModels(EntityManager& em,GameEngine& ge)
{
	//cargar modelos
	//********DATA->fbx********
	////////////8 vertices y Coordenadas de textura
	std::vector<Vertex> vertices =
	{
		Vertex(glm::vec3(-0.5f, -0.5f, 0.0f),glm::vec4(1.f,0.f,0.f,1.f)),
		Vertex(glm::vec3(0.5f, -0.5f, 0.0f),glm::vec4(0.f,0.f,1.f,1.f)),
		Vertex(glm::vec3(0.0f, 0.5f, 0.0f),glm::vec4(0.f,1.f,0.f,1.f)),
		Vertex(glm::vec3(0.0f, 0.5f, 0.0f),glm::vec4(0.f,1.f,0.f,1.f)),

		Vertex(glm::vec3(-0.5f, -0.5f, 0.0f),glm::vec4(1.f,0.f,0.f,1.f)),
		Vertex(glm::vec3(0.5f, -0.5f, 0.0f),glm::vec4(0.f,0.f,1.f,1.f)),
		Vertex(glm::vec3(0.0f, 0.5f, 0.0f),glm::vec4(0.f,1.f,0.f,1.f)),
		Vertex(glm::vec3(0.0f, 0.5f, 0.0f),glm::vec4(0.f,1.f,0.f,1.f)),
	};
	std::array<uint16_t, 3> indices = { 0,1,2 };
	//Crear cubo
	//**************************
	// 
	//Load Model for each entity
	em.forEach<CmpsList, TagList>([&](Entity& e, RenderComponent& rc)
	{
		std::vector<const char*> filepaths;
		filepaths.push_back("../data/front.png");
		filepaths.push_back("../data/top.png");

		rc.model = new Model(ge.LoadModel(filepaths,vertices, indices));
		rc.model->setPosition(rc.position);
		rc.model->setScale(rc.scale);
	});

	/*std::shared_ptr<Buffer> buffer = std::make_shared<Buffer>(vertices, indices);

	std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
	mesh->addBuffer(buffer);*/

	
}

void RenderSystem::UnloadModels(EntityManager& em)
{
	em.forEach<CmpsList, TagList>([&](Entity& e, RenderComponent& rc)
	{
		delete rc.model;
		rc.model = nullptr;
	});
}

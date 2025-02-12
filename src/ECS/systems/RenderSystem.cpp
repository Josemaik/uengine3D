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
	//Triángulo
	std::vector<Vertex> vertices_triangle =
	{
		Vertex(glm::vec3(-0.5f, -0.5f, 0.0f),glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
		Vertex(glm::vec3(0.5f, -0.5f, 0.0f), glm::vec4(0.f,0.f,1.f,1.f),glm::vec2(0.f,0.f)),
		Vertex(glm::vec3(0.0f, 0.5f, 0.0f),  glm::vec4(0.f,1.f,0.f,1.f),glm::vec2(0.f,0.f)),
	};
	//std::array<uint16_t, 3> indices = { 0,1,2 };
	std::vector<uint16_t> indices_triangle = { 0,1,2 };
	//Crear cubo
	//std::vector<Vertex> vertices_cube =
	//{				//position										//color										//textcoords
	//	/*Vertex(glm::vec3(1.0f,-1.0f,-1.0f), glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f))*/,// triangle 1 : begin
	//	Vertex(glm::vec3(-1.0f,-1.0f, 1.0f),glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(1.f,0.f)),
	//	Vertex(glm::vec3(-1.0f, 1.0f, 1.0f),glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(1.f,1.f)), // triangle 1 : end
	//	Vertex(glm::vec3(1.0f, 1.0f,-1.0f), glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),// triangle 2 : begin
	//	Vertex(glm::vec3(-1.0f,-1.0f,-1.0f),glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(-1.0f, 1.0f,-1.0f),glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)), // triangle 2 : end
	//	Vertex(glm::vec3(1.0f,-1.0f, 1.0f),	glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(-1.0f,-1.0f,-1.0f),glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(1.0f,-1.0f,-1.0f),	glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(1.0f, 1.0f,-1.0f),	glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(1.0f,-1.0f,-1.0f),	glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(-1.0f,-1.0f,-1.0f),glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(-1.0f,-1.0f,-1.0f),glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(-1.0f, 1.0f, 1.0f),glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(-1.0f, 1.0f,-1.0f),glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(1.0f,-1.0f, 1.0f),	glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(-1.0f,-1.0f, 1.0f),glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(-1.0f,-1.0f,-1.0f),glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(-1.0f, 1.0f, 1.0f),glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(-1.0f,-1.0f, 1.0f),glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(1.0f,-1.0f, 1.0f),	glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(1.0f,-1.0f,-1.0f),	glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(1.0f, 1.0f,-1.0f),	glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(1.0f,-1.0f,-1.0f),	glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(1.0f,-1.0f, 1.0f),	glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(1.0f, 1.0f,-1.0f),	glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(-1.0f, 1.0f,-1.0f),glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(-1.0f, 1.0f,-1.0f),glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(-1.0f, 1.0f, 1.0f),glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	Vertex(glm::vec3(-1.0f, 1.0f, 1.0f),glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
	//	 Vertex(glm::vec3(1.0f,-1.0f, 1.0f),glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f))
	//};
	//std::vector<uint16_t> indices_cube{ 0,1,2,3,4,5,6,
	//																		7,8,9,10,11,12,
	//																		13,14,15,16,17,18,
	//																		19,20,21,22,23,24,
	//																		25,26,27,28,29,30,
	//																		31,32,33,34,35,36
	//																	};
	
std::vector<Vertex> vertices_cube{
		// Front face
		Vertex(glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(0.f, 0.f)),
		Vertex(glm::vec3(1.0f, -1.0f, 1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(1.f, 0.f)),
		Vertex(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(1.f, 1.f)),
		Vertex(glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(0.f, 1.f)),

		// Back face
		Vertex(glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(0.f, 0.f)),
		Vertex(glm::vec3(-1.0f, 1.0f, -1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(0.f, 1.f)),
		Vertex(glm::vec3(1.0f, 1.0f, -1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(1.f, 1.f)),
		Vertex(glm::vec3(1.0f, -1.0f, -1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(1.f, 0.f)),

		// Top face
		Vertex(glm::vec3(-1.0f, 1.0f, -1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(0.f, 0.f)),
		Vertex(glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(0.f, 1.f)),
		Vertex(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(1.f, 1.f)),
		Vertex(glm::vec3(1.0f, 1.0f, -1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(1.f, 0.f)),

		// Bottom face
		Vertex(glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(0.f, 0.f)),
		Vertex(glm::vec3(1.0f, -1.0f, -1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(1.f, 0.f)),
		Vertex(glm::vec3(1.0f, -1.0f, 1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(1.f, 1.f)),
		Vertex(glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(0.f, 1.f)),

		// Right face
		Vertex(glm::vec3(1.0f, -1.0f, -1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(0.f, 0.f)),
		Vertex(glm::vec3(1.0f, 1.0f, -1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(0.f, 1.f)),
		Vertex(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(1.f, 1.f)),
		Vertex(glm::vec3(1.0f, -1.0f, 1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(1.f, 0.f)),

		// Left face
		Vertex(glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(0.f, 0.f)),
		Vertex(glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(1.f, 0.f)),
		Vertex(glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(1.f, 1.f)),
		Vertex(glm::vec3(-1.0f, 1.0f, -1.0f), glm::vec4(1.f, 0.f, 0.f, 1.f), glm::vec2(0.f, 1.f))
};

std::vector< std::vector<uint16_t>> vector_indices;
std::vector<uint16_t> indices_cube =
{
		0, 1, 2, 2, 3, 0,  // Front
		4, 5, 6, 6, 7, 4,  // Back
		8, 9, 10, 10, 11, 8,  // Top
		12, 13, 14, 14, 15, 12,  // Bottom
		16, 17, 18, 18, 19, 16,  // Right
		20, 21, 22, 22, 23, 20   // Left
};
std::vector<uint16_t> indices_cube_front =
{
		0, 1, 2, 2, 3, 0,  // Front
		4, 5, 6, 6, 7, 4,  // Back
		/*8, 9, 10, 10, 11, 8,  // Top
		12, 13, 14, 14, 15, 12,*/  // Bottom
		16, 17, 18, 18, 19, 16,  // Right
		20, 21, 22, 22, 23, 20   // Left
};
std::vector<uint16_t> indices_cube_topdown =
{
		8, 9, 10, 10, 11, 8,  // Top
		12, 13, 14, 14, 15, 12  // Bott
};
	//**************************
	// 
	//Load Model for each entity
	em.forEach<CmpsList, TagList>([&](Entity& e, RenderComponent& rc)
	{
		std::vector<const char*> filepaths;

		if (e.hasTag<triangleTag>())
		{
			vector_indices.push_back(indices_triangle);
			rc.model = new Model(ge.LoadModel(filepaths, vertices_triangle, vector_indices));
		}
		if (e.hasTag<cubeTag>())
		{
			//vector_indices.push_back(indices_cube);
			filepaths.push_back("../data/front.png");
			vector_indices.push_back(indices_cube_front);

			filepaths.push_back("../data/top.png");
			vector_indices.push_back(indices_cube_topdown);

			rc.model = new Model(ge.LoadModel(filepaths, vertices_cube, vector_indices));
		}

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

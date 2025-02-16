#include "RenderSystem.hpp"

#include "../../managers/GameEngine.hpp"

void RenderSystem::update(EntityManager& em, float dt)
{
	em.forEach<CmpsList, TagList>([&](Entity& e,RenderComponent& rc)
	{
		//Update rotation
		rc.currentangle += rc.angularvelocity * dt;
		rc.model->setRotation(glm::angleAxis(glm::radians(rc.currentangle), glm::vec3(0, 1, 0)));
		//Draw
		rc.model->draw();
	});
}

void RenderSystem::LoadModels(EntityManager& em,GameEngine& ge)
{
	//Load Model for each entity
	em.forEach<CmpsList, TagList>([&](Entity& e, RenderComponent& rc)
	{
		std::vector<const char*> texturepaths; //texturas
		std::vector< std::vector<uint16_t>> vector_indices; //indices

		if (e.hasTag<triangleTag>())
		{
			//Triangle Data
			std::vector<Vertex> vertices_triangle =
			{
				Vertex(glm::vec3(-0.5f, -0.5f, 0.0f),glm::vec4(1.f,0.f,0.f,1.f),glm::vec2(0.f,0.f)),
				Vertex(glm::vec3(0.5f, -0.5f, 0.0f), glm::vec4(0.f,0.f,1.f,1.f),glm::vec2(0.f,0.f)),
				Vertex(glm::vec3(0.0f, 0.5f, 0.0f),  glm::vec4(0.f,1.f,0.f,1.f),glm::vec2(0.f,0.f)),
			};
			std::vector<uint16_t> indices_triangle = { 0,1,2 };
			//Load Model
			vector_indices.push_back(indices_triangle);
			rc.model = new Model(ge.LoadModelCodec(texturepaths, vertices_triangle, vector_indices));
		}
		if (e.hasTag<boxTag>())
		{
			//Cube Data								};
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
			//Load Model
			texturepaths.push_back("../data/front.png");
			vector_indices.push_back(indices_cube_front);

			texturepaths.push_back("../data/top.png");
			vector_indices.push_back(indices_cube_topdown);

			rc.model = new Model(ge.LoadModelCodec(texturepaths, vertices_cube, vector_indices));
		}

		//BoxStack
		if(e.hasTag<boxStackTag>())
			rc.model = new Model(ge.LoadModel("../data/models/box_stack.obj"));
		//GunSlinger
		if (e.hasTag<gunslingerTag>())
			rc.model = new Model(ge.LoadModel("../data/models/gunslinger.obj"));

		//Set position and scale
		rc.model->setPosition(rc.position);
		rc.model->setScale(rc.scale);
	});

}

void RenderSystem::UnloadModels(EntityManager& em)
{
	em.forEach<CmpsList, TagList>([&](Entity& e, RenderComponent& rc)
	{
		delete rc.model;
		rc.model = nullptr;
	});
}

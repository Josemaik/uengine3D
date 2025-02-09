#ifdef _MSC_VER
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

//std
#include <iostream>
#include <vector>
#include <array>
//strings
#include <sstream>
#include <fstream>
#include <string>


//opengl, glfw, renderer
#include "managers/GameEngine.hpp"
#include "renderer/resources/Shader.h"
#include "renderer/resources/Vertex.h"
#include "renderer/resources/Buffer.h"
//#include "renderer/resources/State.hpp"
#include "ECS/types.hpp"
#include "ECS/systems/RenderSystem.hpp"
//#include "../glfw/glfw3.h"
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/quaternion.hpp"


#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

//static std::string readString(const std::string& filename) {
//	std::ifstream istream(filename.c_str(), std::ios_base::binary);
//	std::stringstream sstream;
//	sstream << istream.rdbuf();
//	return sstream.str();
//}
// CreateTriangle(EntityManager& em,glm::vec3 pos)
//{
//	auto& triangle{ em.createEntity() };
//	auto& r = em.addComponent<RenderComponent>(triangle);
//	std::shared_ptr<Buffer> buffer = std::make_shared<Buffer>(r.vertices, r.indices);
//	std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
//	mesh->addBuffer(buffer);
//	r.model = std::make_shared<Model>(mesh);
//	//r.model->setPosition(glm::vec3(0.f, 0.f, 0.f));
//	r.model->setPosition(pos);
//	r.model->setScale(glm::vec3(1.f, 1.f, 1.f));
//}

int main() {
	//Inicializamos Engine
	ENGI::GameEngine engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	//Inicializamos ECS
	EntityManager em{};
	//systems
	RenderSystem rsys{};

	/*std::vector<Vertex> vertices =
	{
		Vertex(glm::vec3(-0.5f, -0.5f, 0.0f),glm::vec4(1.f,0.f,0.f,1.f)),
		Vertex(glm::vec3(0.5f, -0.5f, 0.0f),glm::vec4(0.f,0.f,1.f,1.f)),
		Vertex(glm::vec3(0.0f, 0.5f, 0.0f),glm::vec4(0.f,1.f,0.f,1.f))
	};
	std::array<uint16_t, 3> indices = { 0,1,2 };
	Buffer buffer(vertices, indices);*/
	//Creamos 9 entidades -> trángulos
	//int row = 0, col = 0;
	//for (int i = 0; i < 9; i++)
	//{
	//	if (i % 3 == 0) row++; col = 0;

	//	auto position = glm::vec3(col * 3.f - 3.f, 0.0f, -row * 3.0f);
	//	auto& triangle{ em.createEntity() };
	//	auto& r = em.addComponent<RenderComponent>(triangle);

	//	//Create Buffer
	//	//Buffer buffer(r.vertices, r.indices);
	//	const std::shared_ptr<Buffer> buffer = std::make_shared<Buffer>(r.vertices, r.indices);
	//	//Create Mesh
	//	//Mesh mesh{};
	//	//mesh.addBuffer(buffer, nullptr);
	//	const std::shared_ptr<Mesh> & mesh = std::make_shared<Mesh>();
	//	mesh->addBuffer(buffer, nullptr);
	//	//Create Model
	//	r.model = new Model(mesh);
	//	r.model->setPosition(position);
	//	r.model->setScale(glm::vec3(1.f, 1.f, 1.f));

	//	col++;
	//}
	//triángulo de prueba
	//Create Shaders
	Shader shader("../data/vertex.glsl", "../data/fragment.glsl");
	//Pasa a ser el Shader por defecto
	shader.AttachandLink();
	//Use Program
	shader.use();
	//Pasarlo como defaultshader
	State::defaultShader = std::make_shared<Shader>(shader);

	//int row = 0, col = 0;
	//for (int i = 0; i < 9; i++)
	//{
	//	if (i % 3 == 0) row++; col = 0;

	//	auto& triangle{ em.createEntity() };
	//	auto& r = em.addComponent<RenderComponent>(triangle);
	//	const std::shared_ptr<Buffer>& buffer = std::make_shared<Buffer>(r.vertices, r.indices);
	//	const std::shared_ptr<Mesh>& mesh = std::make_shared<Mesh>();
	//	mesh->addBuffer(buffer);
	//	r.model = new Model(mesh);
	//	//r.model->setPosition(glm::vec3(0.f, 0.f, 0.f));
	//	r.model->setPosition(glm::vec3(col * 3.f - 3.f, 0.0f, -row * 3.0f));
	//	r.model->setScale(glm::vec3(1.f, 1.f, 1.f));
	//}
	//CreateTriangle(em,glm::vec3(0.f, 0.f, 0.f));
	std::vector<Vertex> vertices =
	{
		Vertex(glm::vec3(-0.5f, -0.5f, 0.0f),glm::vec4(1.f,0.f,0.f,1.f)),
		Vertex(glm::vec3(0.5f, -0.5f, 0.0f),glm::vec4(0.f,0.f,1.f,1.f)),
		Vertex(glm::vec3(0.0f, 0.5f, 0.0f),glm::vec4(0.f,1.f,0.f,1.f))
	};
	std::array<uint16_t, 3> indices = { 0,1,2 };
	std::shared_ptr<Buffer> buffer = std::make_shared<Buffer>(vertices, indices);

	std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
	mesh->addBuffer(buffer);


		//auto& triangle{ em.createEntity() };
		//auto& r = em.addComponent<RenderComponent>(triangle);
		//std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
		//mesh->addBuffer(buffer);
		//r.model = std::make_shared<Model>(mesh);
		////r.model->setPosition(glm::vec3(0.f, 0.f, 0.f));
		//r.model->setPosition(glm::vec3(0.f, 0.f, 0.f));
		//r.model->setScale(glm::vec3(1.f, 1.f, 1.f));

		//auto& triangle2{ em.createEntity() };
		//auto& r2 = em.addComponent<RenderComponent>(triangle2);
		////std::shared_ptr<Buffer> buffer2 = std::make_shared<Buffer>(r2.vertices, r2.indices);
		//std::shared_ptr<Mesh> mesh2 = std::make_shared<Mesh>();
		//mesh2->addBuffer(buffer);
		//r2.model = std::make_shared<Model>(mesh2);
		////r.model->setPosition(glm::vec3(0.f, 0.f, 0.f));
		//r2.model->setPosition(glm::vec3(-3.f, 0.f, -6.f));
		//r2.model->setScale(glm::vec3(1.f, 1.f, 1.f));

		//auto& triangle3{ em.createEntity() };
		//auto& r3 = em.addComponent<RenderComponent>(triangle3);
		////std::shared_ptr<Buffer> buffer3 = std::make_shared<Buffer>(r3.vertices, r3.indices);
		//std::shared_ptr<Mesh> mesh3 = std::make_shared<Mesh>();
		//mesh3->addBuffer(buffer);
		//r3.model = std::make_shared<Model>(mesh3);
		////r.model->setPosition(glm::vec3(0.f, 0.f, 0.f));
		//r3.model->setPosition(glm::vec3(3.f, 0.f, -6.f));
		//r3.model->setScale(glm::vec3(1.f, 1.f, 1.f));
		//std::vector<glm::vec3> positions = {
		//	{0.f, 0.f, 0.f},     // Triángulo 1
		//	{-3.f, 0.f, -6.f},   // Triángulo 2
		//	{3.f, 0.f, -6.f}     // Triángulo 3
		//};
		//for (const auto& pos : positions) {
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			auto& triangle = em.createEntity();
			auto& r = em.addComponent<RenderComponent>(triangle);

			r.model = new Model(mesh);
			r.model->setPosition(glm::vec3(col * 3.f - 3.f, 0.0f, -row * 3.0f));
			r.model->setScale(glm::vec3(1.f, 1.f, 1.f));
		}
	}
		//}

	//std::vector<glm::vec3> positions = {
	//	{0.f, 0.f, 0.f},     // Triángulo 1
	//	{-3.f, 0.f, -6.f},   // Triángulo 2
	//	{3.f, 0.f, -6.f}     // Triángulo 3
	//};
	//for (const auto& pos : positions) {
	//	auto& triangle = em.createEntity();
	//	auto& r = em.addComponent<RenderComponent>(triangle);

	//	const std::shared_ptr<Buffer> &buffer = std::make_shared<Buffer>(r.vertices, r.indices);
	//	std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
	//	mesh->addBuffer(buffer);

	//	//r.model = new Model(mesh);
	//	r.model = std::make_shared<Model>(mesh);
	//	r.model->setPosition(pos);
	//	r.model->setScale(glm::vec3(1.f, 1.f, 1.f));
	//}
	//for (auto& e : em.getEntities())
	//{

	//	auto& rc = em.getComponent<RenderComponent>(e);
	//	if (!rc.model) {
	//		std::cout << "Error: rc.model es nullptr!" << std::endl;
	//	}
	//	else if (!rc.model->getMesh()) {
	//		std::cout << "Error: rc.model->getMesh() es nullptr!" << std::endl;
	//	}
	//	else {
	//		std::cout << "Buffers en el mesh: " << rc.model->getMesh()->getNumBuffers() << std::endl;
	//	}
	//	printf("Size buffer: %d", rc.model->getMesh()->getNumBuffers());
	//}

		//for (int row = 0; row < 3; row++)
		//{
		//	for (int col = 0; col < 3; col++)
		//	{
		//		auto& triangle{ em.createEntity() };
		//		auto& r = em.addComponent<RenderComponent>(triangle);
		//		const std::shared_ptr<Buffer>& buffer = std::make_shared<Buffer>(r.vertices, r.indices);
		//		const std::shared_ptr<Mesh>& mesh = std::make_shared<Mesh>();
		//		mesh->addBuffer(buffer);
		//		r.model = new Model(mesh);
		//		//r.model->setPosition(glm::vec3(0.f, 0.f, 0.f));
		//		r.model->setPosition(glm::vec3(col * 3.f - 3.f, 0.0f, -row * 3.0f));
		//		r.model->setScale(glm::vec3(1.f, 1.f, 1.f));
		//	}
		//}
	////update viewport
	//engine.UpdateViewport();
	//rsys.Init();
	
	// main loop
	//float angle = 0;
	double lastTime = engine.GetTime();
	while (!engine.windowShouldClose() && !engine.IsScapeDown()) {
		// get delta time
		float deltaTime = static_cast<float>(engine.GetTime() - lastTime);
		lastTime = engine.GetTime();

		//Begin Frame
		engine.beginFrame();
		//update viewport
		//engine.UpdateViewport();
		rsys.update(em, lastTime);
		//Draw Triangles
		//View and Project Matrix
		//glm::mat4 view = glm::lookAt(
		//	glm::vec3(0.0f, 0.0f, 6.0f), //camera pos
		//	glm::vec3(0.0f, 0.0f, 0.0f), //origen escena
		//	glm::vec3(0.0f, 1.0f, 0.0f)); //world direction

		//glm::mat4 proj = glm::perspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);

		/*for (int row = 0; row < 3; row++)
		{*/
		/*	for (int col = 0; col < 3; col++)
			{*/
				//Model Matrix
				//glm::mat4 model = glm::mat4(1.0f);

				//Update angle
				//float angle = 32.0f * static_cast<float>(lastTime);
				//Calculaye quaternion
				//glm::quat rotation = glm::angleAxis(glm::radians(angle), glm::vec3(0, 1, 0)); // Rotate Y

				//model = glm::translate(model, glm::vec3(col * 3.f - 3.f, 0.0f, -row * 3.0f)); //Translation
				//
				//model = model * glm::mat4_cast(rotation);	//Rotate and Translate

				//glm::mat4 mvp = proj * view * model;
				//glm::mat4 mvp = State::projectionMatrix * State::viewMatrix * model;
				//GLint uniMVP = glGetUniformLocation(shader.getID(), "mvp");
				
				//State::defaultShader->setMatrix(uniMVP, mvp);
				//shader.setMatrix(uniMVP, mvp);
				
				//draw triangles
				//buffer.draw(*State::defaultShader.get());
				//buffer.draw(shader);

				//shader.use();
			//}
		//}

		//End frame
		engine.EndFrame();
	}
	rsys.UnloadModels(em);
	// shutdown
	engine.CloseWindow();
	return 0;
}
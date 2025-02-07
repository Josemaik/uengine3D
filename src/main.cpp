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

int main() {
	//Inicializamos Engine
	ENGI::GameEngine engine(SCREEN_WIDTH, SCREEN_HEIGHT);

	//Creamos Buffer
	std::vector<Vertex> vertices =
	{
		Vertex(glm::vec3(-0.5f, -0.5f, 0.0f),glm::vec4(1.f,0.f,0.f,1.f)),
		Vertex(glm::vec3(0.5f, -0.5f, 0.0f),glm::vec4(0.f,0.f,1.f,1.f)),
		Vertex(glm::vec3(0.0f, 0.5f, 0.0f),glm::vec4(0.f,1.f,0.f,1.f))
	};
	std::array<uint16_t, 3> indices = {0,1,2};

	Buffer buffer(vertices, indices);

	//Create Shaders
	Shader shader("../data/vertex.glsl", "../data/fragment.glsl");
	shader.AttachandLink();


	//update viewport
	engine.UpdateViewport();

	//Use Program
	shader.use();
	// main loop
	float angle = 0;
	double lastTime = engine.GetTime();
	while (!engine.windowShouldClose() && !engine.IsScapeDown()) {
		// get delta time
		float deltaTime = static_cast<float>(engine.GetTime() - lastTime);
		lastTime = engine.GetTime();

		//Begin Frame
		engine.beginFrame();

		//Draw Triangles
		//View and Project Matrix
		glm::mat4 view = glm::lookAt(
			glm::vec3(0.0f, 0.0f, 6.0f), //camera pos
			glm::vec3(0.0f, 0.0f, 0.0f), //origen escena
			glm::vec3(0.0f, 1.0f, 0.0f)); //world direction

		glm::mat4 proj = glm::perspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);

		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				//Model Matrix
				glm::mat4 model = glm::mat4(1.0f);

				//Update angle
				float angle = 32.0f * static_cast<float>(lastTime);
				//Calculaye quaternion
				glm::quat rotation = glm::angleAxis(glm::radians(angle), glm::vec3(0, 1, 0)); // Rotate Y

				model = glm::translate(model, glm::vec3(col * 3.f - 3.f, 0.0f, -row * 3.0f)); //Translation

				model = model * glm::mat4_cast(rotation);	//Rotate and Translate

				glm::mat4 mvp = proj * view * model;
				GLint uniMVP = glGetUniformLocation(shader.getID(), "mvp");
				shader.setMatrix(uniMVP, mvp);
				
				//draw triangles
				buffer.draw(shader);

				shader.use();
			}
		}

		//End frame
		engine.EndFrame();
	}
	// shutdown
	engine.CloseWindow();
	return 0;
}
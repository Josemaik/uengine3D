#ifdef _MSC_VER
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

//std
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <stdio.h>
//opengl, glfw, renderer
#include <GL/glew.h>
#include "../src/renderer/Shader.h"
#include "../src/renderer/Vertex.h"
#include "../src/renderer/Buffer.h"
#include "../lib/glfw/glfw3.h"
#include "../lib/glm/gtc/type_ptr.hpp"
#include "../lib/glm/gtc/matrix_transform.hpp"
#include "../lib/glm/gtc/quaternion.hpp"


#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

static std::string readString(const std::string& filename) {
	std::ifstream istream(filename.c_str(), std::ios_base::binary);
	std::stringstream sstream;
	sstream << istream.rdbuf();
	return sstream.str();
}

int main() {
	// init glfw
	if (!glfwInit()) {
		std::cout << "could not initialize glfw" << std::endl;
		return -1;
	}

	// create window
	//glfwInit();
	glfwWindowHint(GLFW_RESIZABLE, false);
	glfwWindowHint(GLFW_SAMPLES, 8);

	GLFWwindow* win = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Rotating Rectangles", nullptr, nullptr);
	if (!win) {
		std::cout << "could not create opengl window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(win);

	//Init GLEW
	if (glewInit())
	{
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_SCISSOR_TEST);
		std::cout << "Error: GLEW can't be initialized!" << std::endl;
	}
	std::cout << "GLEW initialized!\n" << std::endl;
	glBlendFunc(GL_DEPTH_TEST, GL_SCISSOR_TEST);

	std::vector<Vertex> vertices =
	{
		Vertex(glm::vec3(-0.5f, -0.5f, 0.0f),glm::vec4(1.f,0.f,0.f,1.f)),
		Vertex(glm::vec3(0.5f, -0.5f, 0.0f),glm::vec4(0.f,0.f,1.f,1.f)),
		Vertex(glm::vec3(0.0f, 0.5f, 0.0f),glm::vec4(0.f,1.f,0.f,1.f))
	};
	std::array<uint16_t, 6> indices = { 0,1,2};

	Buffer buffer(vertices, indices);

	std::string vertexShaderString = readString(std::string("../data/vertex.glsl"));
	const char* vertexShaderSource = vertexShaderString.c_str();

	std::string fragmentShaderString = readString(std::string("../data/fragment.glsl"));
	const char* fragmentShaderSource = fragmentShaderString.c_str();

	unsigned int vertexShader;
	unsigned int fragmentShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);

	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	int succes;
	char errorLog[512]{};
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &succes);
	if (!succes) {
		char errorLog[1024];
		glGetShaderInfoLog(vertexShader, sizeof(errorLog), nullptr, errorLog);
		glDeleteShader(vertexShader);
		std::cout << errorLog;
	}
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &succes);
	if (!succes) {
		char errorLog[1024];
		glGetShaderInfoLog(fragmentShader, sizeof(errorLog), nullptr, errorLog);
		glDeleteShader(fragmentShader);
		std::cout << errorLog;
	}

	Shader shader(vertexShader, fragmentShader);
	shader.AttachandLink();


	//update viewport
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	glScissor(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	//Use Program
	shader.use();
	// main loop
	float angle = 0;
	double lastTime = glfwGetTime();
	while (!glfwWindowShouldClose(win) && !glfwGetKey(win, GLFW_KEY_ESCAPE)) {
		// get delta time
		float deltaTime = static_cast<float>(glfwGetTime() - lastTime);
		lastTime = glfwGetTime();

		//clear backfround
		glClearColor(0.f, 0.0f, 0.0f, 1.0f);  // black
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// get window size
		/*int screenWidth, screenHeight;
		glfwGetWindowSize(win, &screenWidth, &screenHeight);*/

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
				float angle = 32.0f * lastTime;
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

		// refresh screen
		glfwSwapBuffers(win);
		glfwPollEvents();
	}
	//liberar memoria
	glDeleteProgram(shader.getID());
	// shutdown
	glfwTerminate();
	return 0;
}
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



#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

//static bool Init()
//{
//	if (glewInit() == GLEW_OK)
//	{
//		glEnable(GL_DEPTH_TEST);
//		glEnable(GL_SCISSOR_TEST);
//		return true;
//	}
//	return false;
//}

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
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_SAMPLES, 8);
	GLFWwindow* win = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Rotating Rectangles", nullptr, nullptr);
	if (!win) {
		std::cout << "could not create opengl window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(win);
	//check gl version and renderer
	/*const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* vendor = glGetString(GL_VENDOR);
	const GLubyte* version = glGetString(GL_VERSION);
	std::cout << "Renderer: " << renderer << std::endl;
	std::cout << "Vendor: " << vendor << std::endl;
	std::cout << "OpenGL Version: " << version << std::endl;*/

	//Init GLEW
	if (glewInit())
	{
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_SCISSOR_TEST);
		std::cout << "Error: GLEW can't be initialized!" << std::endl;
	}
	std::cout << "GLEW initialized!\n" << std::endl;
	glBlendFunc(GL_DEPTH_TEST, GL_SCISSOR_TEST);
	// //Init GLAD
	// if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	// {
	// 	std::cout << "Error: GLAD can't be initialized!" << std::endl;
	// }

	///////////////////////////////////
	// implementacion prueba
	// ////////////////////////////////
	/*float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f, 0.5f, 0.0f,
	};*/
	std::vector<Vertex> vertices =
	{
		Vertex(glm::vec3(-0.5f, -0.5f, 0.0f),glm::vec4(1.f,0.f,0.f,1.f)),
		Vertex(glm::vec3(0.5f, -0.5f, 0.0f),glm::vec4(0.f,0.f,1.f,1.f)),
		Vertex(glm::vec3(0.0f, 0.5f, 0.0f),glm::vec4(0.f,1.f,0.f,1.f))
		/*Vertex(glm::vec3(-0.5f, -0.5f, 0.0f),glm::vec4(1.f,0.f,0.f,1.f)),
		Vertex(glm::vec3(0.5f, -0.5f, 0.0f),glm::vec4(0.f,0.f,1.f,1.f)),
		Vertex(glm::vec3(0.0f, 0.5f, 0.0f),glm::vec4(0.f,1.f,0.f,1.f)),*/
	};

	/*Vertex *vertices = new Vertex[3]
	{
		Vertex(glm::vec3(-0.5f, -0.5f, 0.0f)),
		Vertex(glm::vec3(0.5f, -0.5f, 0.0f)),
		Vertex(glm::vec3(0.0f, 0.5f, 0.0f))
	};*/
	std::array<uint16_t, 6> indices = { 0,1,2/*,3,4,5*/ };

	Buffer buffer(vertices, indices);


	//unsigned int vao; // vertex array object
	//glGenVertexArrays(1, &vao);

	//unsigned int vbo;
	//glGenBuffers(1, &vbo);

	//glBindVertexArray(vao); // se guardan configuraciones que haga

	//glBindBuffer(GL_ARRAY_BUFFER, vbo);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<const
	//	void*>(offsetof(Vertex, position)));// 3 * sizeof(float)(void*)0
	//
	//glEnableVertexAttribArray(0);

	//glBindVertexArray(0);

	std::string vertexShaderString = readString(std::string("../data/vertex.glsl"));
	const char* vertexShaderSource = vertexShaderString.c_str();
	/*const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";*/
	std::string fragmentShaderString = readString(std::string("../data/fragment.glsl"));
	const char* fragmentShaderSource = fragmentShaderString.c_str();
	/*const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n";*/

	unsigned int vertexShader;
	unsigned int fragmentShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);

	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	int succes;
	char errorLog[512];
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
	/*unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram);
	glGetShaderiv(shaderProgram, GL_LINK_STATUS, &succes);
	if (!succes) {
		char errorLog[1024];
		glGetShaderInfoLog(fragmentShader, sizeof(errorLog), nullptr, errorLog);
		std::cout << "Error link";
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);*/


	//update viewport
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	glScissor(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	//glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);

	//glUseProgram(shaderProgram);
	shader.use();
	// main loop
	//float angle = 0;
	//double lastTime = glfwGetTime();
	while (!glfwWindowShouldClose(win) && !glfwGetKey(win, GLFW_KEY_ESCAPE)) {
		// get delta time
		//float deltaTime = static_cast<float>(glfwGetTime() - lastTime);
		//lastTime = glfwGetTime();

		//clear backfround
		glClearColor(0.f, 0.0f, 0.0f, 1.0f);  // black

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// get window size
		/*int screenWidth, screenHeight;
		glfwGetWindowSize(win, &screenWidth, &screenHeight);*/

		//Set up MVP
		glm::mat4 model = glm::mat4(1.0f);

		glm::mat4 view = glm::lookAt(
			glm::vec3(0.0f, 0.0f, 6.0f), //camera pos
			glm::vec3(0.0f, 0.0f, 0.0f), //origen escena
			glm::vec3(0.0f, 1.0f, 0.0f)); //world direction

		glm::mat4 proj = glm::perspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);

		glm::mat4 mvp = proj * view * model;
		//GLint uniMVP = shader.getLocation("mvp");
		GLint uniMVP = glGetUniformLocation(shader.getID(), "mvp");
		shader.setMatrix(uniMVP, mvp);

		//draw triangles
		buffer.draw(shader);

		shader.use();
		/*glBindVertexArray(vao);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindVertexArray(0);*/

		// refresh screen
		glfwSwapBuffers(win);
		glfwPollEvents();
	}
	//liberar memoria
	glDeleteProgram(shader.getID());
	/*glDeleteBuffers(1,&buffer.m_vbo);
	glDeleteVertexArrays(1, &buffer.m_vao);*/
	/*glDeleteBuffers(1, &vao);
	glDeleteVertexArrays(1, &vbo);*/
	// shutdown
	glfwTerminate();
	return 0;
}
#ifdef _MSC_VER
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif


#include <GL/glew.h>
#include "../lib/glfw/glfw3.h"
#include <iostream>
#include <vector>
#include "../project/Shader.h"
#include <sstream>
#include <fstream>
#include <string>
#include "../project/Vertex.h"
#include <vector>
#include <array>
#include "../project/Buffer.h"


#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

static bool Init()
{
	if (glewInit() == GLEW_OK)
	{
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_SCISSOR_TEST);
		return true;
	}
	return false;
}

static std::string readString(const std::string& filename) {
	std::ifstream istream(filename.c_str(), std::ios_base::binary);
	std::stringstream sstream;
	sstream << istream.rdbuf();
	return sstream.str();
}

int main() {
	// init glfw
	if ( !glfwInit() ) {
		std::cout << "could not initialize glfw" << std::endl;
		return -1;
	}

	// create window
	//glfwWindowHint(GLFW_RESIZABLE, false);
	glfwWindowHint(GLFW_SAMPLES, 8);
	GLFWwindow* win = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "", nullptr, nullptr);
	if (!win) {
		std::cout << "could not create opengl window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(win);

	//Init
	if (!Init())
	{
		std::cout << "Error: GLEW can't be initialized!" << std::endl;
	}
	std::cout << "GLEW initialized!" << std::endl;

	//Vertex Shader Creation
	//get source
	std::string vertexshaderfilename = readString(std::string("../data/vertex.glsl"));
	const char* vertexShaderSource = vertexshaderfilename.c_str();
	//Create
	GLuint vertexshader = glCreateShader(GL_VERTEX_SHADER);
	//attach the shader source code to the shader object
	glShaderSource(vertexshader, 1, &vertexShaderSource, nullptr);

	//Fragment Shader Creation
	//get source
	std::string fragmentshaderfilename = readString(std::string("../data/fragment.glsl"));
	const char* fragmentShaderSource = fragmentshaderfilename.c_str();
	//Create
	GLuint fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
	//attach the shader source code to the shader object
	glShaderSource(fragmentshader, 1, &fragmentShaderSource, nullptr);

	//Create Shader Object Instance
	Shader shader(vertexshader, fragmentshader);

	//Compile Vertex Shader
	int retCode_v;
	glCompileShader(vertexshader);
	glGetShaderiv(vertexshader, GL_COMPILE_STATUS,&retCode_v);
	if(retCode_v == GL_FALSE) {
		char errorLog[1024];
		glGetShaderInfoLog(vertexshader, sizeof(errorLog), nullptr, errorLog);
		shader.error_vertex_shader = errorLog;
		glDeleteShader(vertexshader);
	}
	//Compile Fragment Shader
	int retCode_f;
	glCompileShader(fragmentshader);
	glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &retCode_f);
	if (retCode_f == GL_FALSE) {
		char errorLog[1024];
		glGetShaderInfoLog(fragmentshader, sizeof(errorLog), nullptr, errorLog);
		shader.error_fragment_shader = errorLog;
		glDeleteShader(fragmentshader);
	}
	
	//Activamos su uso
	shader.use();
	//Check link status
	//Comprobar si el linkado ha funcionado
	int retCode;
	glGetProgramiv(shader.getID(), GL_LINK_STATUS, &retCode);
	if (retCode == GL_FALSE) {
		char errorLog[1024];
		glGetProgramInfoLog(shader.getID(), sizeof(errorLog), nullptr, errorLog);
		shader.error_link_program = errorLog;
		glDeleteProgram(shader.getID());
		shader.idProgram = 0;
	}

	//Setup attributes
	shader.setupAttribs();

	//Buffer
	std::vector<Vertex> vertices = {
	 Vertex(glm::vec3(0, 0.5f, 0)),
	 Vertex(glm::vec3(-0.5f, -0.5f, 0)),
	 Vertex(glm::vec3(0.5f, -0.5f, 0))
	};
	std::array<uint16_t, 3> indices = { 0,1,2 };
	Buffer buffer(vertices,indices);
	
	// main loop
	//float angle = 0;
	//double lastTime = glfwGetTime();
	while ( !glfwWindowShouldClose(win) && !glfwGetKey(win, GLFW_KEY_ESCAPE) ) {
		// get delta time
		//float deltaTime = static_cast<float>(glfwGetTime() - lastTime);
		//lastTime = glfwGetTime();

		// get window size
		int screenWidth, screenHeight;
		glfwGetWindowSize(win, &screenWidth, &screenHeight);

		

		// refresh screen
		glfwSwapBuffers(win);
		glfwPollEvents();
	}

	// shutdown
	glfwTerminate();
}
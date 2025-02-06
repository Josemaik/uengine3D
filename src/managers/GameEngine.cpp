#include "GameEngine.hpp"
#include <iostream>

ENGI::GameEngine::GameEngine(int const _width, int const _height)
	:width(_width),height(_height)
{
	// init glfw
	if (!glfwInit()) {
		std::cout << "could not initialize glfw" << std::endl;
	}

	glfwWindowHint(GLFW_RESIZABLE, false);
	glfwWindowHint(GLFW_SAMPLES, 8);

	//create window

	window = glfwCreateWindow(width, height, "Rotating Rectangles", nullptr, nullptr);
	if (!window) {
		std::cout << "could not create opengl window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	//Init glew
	if (glewInit())
	{
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_SCISSOR_TEST);
		std::cout << "GLEW initialized!" << std::endl;
	}
	glBlendFunc(GL_DEPTH_TEST, GL_SCISSOR_TEST);
}

double ENGI::GameEngine::GetTime() const
{
	return glfwGetTime();
}

bool ENGI::GameEngine::windowShouldClose() const
{
	return glfwWindowShouldClose(window);
}

GLFWwindow* ENGI::GameEngine::GetWindow() const
{
	if(window)
		return window;
}

void ENGI::GameEngine::CloseWindow() const
{
	glfwTerminate();
}

void ENGI::GameEngine::UpdateViewport() const
{
	glViewport(0, 0, width, height);
	glScissor(0, 0, width, height);
}

bool ENGI::GameEngine::IsScapeDown() const
{
	return glfwGetKey(window, GLFW_KEY_ESCAPE);
}

void ENGI::GameEngine::beginFrame()
{
	//clear backfround
	glClearColor(0.f, 0.0f, 0.0f, 1.0f);  // black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void ENGI::GameEngine::EndFrame()
{
	// refresh screen
	glfwSwapBuffers(window);
	glfwPollEvents();
}

#include "WindowsManager.hpp"
#include <iostream>

bool WindowsManager::InitWindow(int width, int height, const char* title)
{
	m_width = width;
	m_height = height;
	// init glfw
	if (!glfwInit()) {
		std::cout << "could not initialize glfw" << std::endl;
		return false;
	}

	glfwWindowHint(GLFW_RESIZABLE, false);
	glfwWindowHint(GLFW_SAMPLES, 8);

	//create window
	m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (!m_window) {
		std::cout << "could not create opengl window" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(m_window);

	//Init glew
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Error initializing GLEW" << std::endl;
		glfwTerminate();
		return false;
	}
	std::cout << "GLEW initialized!" << std::endl;
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_SCISSOR_TEST);
	glBlendFunc(GL_DEPTH_TEST, GL_SCISSOR_TEST);


	return true;
}

bool WindowsManager::windowShouldClose() const
{
	return m_window && glfwWindowShouldClose(m_window);
}

void WindowsManager::closeWindow()
{
	if (m_window) {
		glfwDestroyWindow(m_window);
	}
	glfwTerminate();
}

void WindowsManager::beginDrawing()
{
	//clear backfround
	glClearColor(0.f, 0.0f, 0.0f, 1.0f);  // black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void WindowsManager::endDrawing()
{
	// refresh screen
	glfwSwapBuffers(m_window);
	glfwPollEvents();
}

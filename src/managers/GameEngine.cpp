#include "GameEngine.hpp"
#include <iostream>
#include <gtc/matrix_transform.hpp>
#include <vector>

ENGI::GameEngine::GameEngine(int const _width, int const _height)
	:width(_width),height(_height)
{
	if (InitWindow(_width,_height,"JsMEngine"))
	{
		std::cout << "Window Initialized succesfully\n";
		//Inicializar input
		//pointer
		//Initialize Camera
		auto camera = m_renderManager.CreateCamera(glm::vec3(0.0f, 0.0f, 6.0f),
																 glm::vec3(0.0f, 0.0f, 0.0f),
																 glm::vec3(0.0f, 1.0f, 0.0f));
		camera->setClearColor(glm::vec3(0.f, 0.f, 0.f));
		camera->setProjection(glm::perspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f));
		camera->setViewport(glm::ivec4(0, 0, width, height));
		//Initialize Shader
		m_renderManager.LoadShader();
	}
}

/////////////////
//TIME
double ENGI::GameEngine::GetTime() const
{
	return glfwGetTime();
}

//////////////
///WINDOW
bool ENGI::GameEngine::InitWindow(int width, int height, const char* title)
{
	return m_windowsManager.InitWindow(width, height, title);
}

bool ENGI::GameEngine::windowShouldClose() const
{
	return m_windowsManager.windowShouldClose();
}

GLFWwindow* ENGI::GameEngine::GetWindow() const
{
	return m_windowsManager.getWindow();
}

void ENGI::GameEngine::CloseWindow() const
{
	m_windowsManager.closeWindow();
}

void ENGI::GameEngine::EndFrame()
{
	m_windowsManager.endDrawing();
}
/////////////
//INPUT
bool ENGI::GameEngine::IsScapeDown() const
{
	return glfwGetKey(GetWindow(), GLFW_KEY_ESCAPE);
}

/////////////
///RENDERER
void ENGI::GameEngine::beginFrame()
{
	m_renderManager.drawCamera();
}

/////////////
///RESOURCE
std::shared_ptr<Mesh>& ENGI::GameEngine::LoadModel(std::vector<Vertex>& vertices, std::array<uint16_t, 3>& indices)
{
	return m_resourceManager.loadResource<Mesh>(vertices, indices);
}

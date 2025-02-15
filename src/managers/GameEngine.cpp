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
		auto camera = m_renderManager.CreateCamera(glm::vec3(-1.0f, 2.0f, 6.0f),
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
Mesh* ENGI::GameEngine::LoadModel(std::vector<const char*>& filepaths,std::vector<Vertex>& vertices, std::vector< std::vector<uint16_t>> indices)
{
	auto textura_front = m_resourceManager.loadResource<Texture>(filepaths[0]);
	auto textura1_top = m_resourceManager.loadResource<Texture>(filepaths[1]);

	auto mat_front = m_resourceManager.loadResource<Material>("material_box_front");
	auto mat_top = m_resourceManager.loadResource<Material>("material_box_top");
	mat_front->setTexture(textura_front);
	mat_top->setTexture(textura1_top);

	std::shared_ptr<Buffer> bufferBox = std::make_shared<Buffer>(vertices, indices[0]);
	std::shared_ptr<Buffer> bufferBox1 = std::make_shared<Buffer>(vertices, indices[1]);

	auto mesh = m_resourceManager.loadResource<Mesh>("caja");
	mesh->addBuffer(bufferBox,*mat_front);
	mesh->addBuffer(bufferBox1,*mat_top);

	return mesh;
}

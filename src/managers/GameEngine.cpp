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
		auto camera = m_renderManager.CreateCamera(glm::vec3(-1.0f, 4.0f, 6.0f),
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

Texture* ENGI::GameEngine::LoadTexture2D(const char* filepath)
{
	return m_resourceManager.loadResource<Texture>(filepath);
}
//Load Model -> OBJ
Mesh* ENGI::GameEngine::LoadModel(const char* filepath)
{
	auto mesh = m_resourceManager.loadResource<Mesh>(filepath);
	auto textpaths = mesh->getTexturePaths();
	for (unsigned int i = 0; i < mesh->getNumBuffers(); i++)
	{
		mesh->getMaterial(i).setTexture(LoadTexture2D(textpaths[i].c_str()));
	}
	return mesh;
}

///Load Model-> vertices and indices writed in code
Mesh* ENGI::GameEngine::LoadModelCodec(std::vector<const char*>& textures,std::vector<Vertex>& vertices, std::vector< std::vector<uint16_t>> indices)
{
	auto mesh = m_resourceManager.loadResource<Mesh>("");
	if (textures.size() > 0) //Meshes with texturez
	{
		for (unsigned int i = 0; i < textures.size(); i++)
		{
			std::shared_ptr<Buffer> bufferBox = std::make_shared<Buffer>(vertices, indices[i]);
			auto mat = m_resourceManager.loadResource<Material>("material_box");
			mat->setTexture(LoadTexture2D(textures[i]));
			mesh->addBuffer(bufferBox, *mat);
		}
	}
	else { //Meshes without texture
		std::shared_ptr<Buffer> buffer = std::make_shared<Buffer>(vertices, indices[0]);
		mesh->addBuffer(buffer);
	}
	
	return mesh;
}

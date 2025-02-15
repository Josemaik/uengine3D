#pragma once

#ifndef GAME_ENGINE
#define GAME_ENGINE

#include "../renderer/managers/WindowsManager.hpp"
#include "../renderer/managers/RenderManager.hpp"
#include "../renderer/managers/ResourceManager.hpp"

namespace ENGI
{
	class GameEngine
	{
	public:
		GameEngine(int const width, int const height);
		~GameEngine(){}

		//Time
		double GetTime() const;

		//Window
		bool InitWindow(int width, int height, const char* title);
		bool windowShouldClose() const;
		GLFWwindow* GetWindow() const;
		void CloseWindow() const;
		//void UpdateViewport() const;
		
		//Input
		bool IsScapeDown() const;

		//Renderer
		void beginFrame();
		void EndFrame();
		//Resource
		Texture* LoadTexture2D(const char* filepath);
		Mesh* LoadModel(const char* filepath);
		Mesh* LoadModelCodec(std::vector<const char*>& filepaths, std::vector<Vertex>& vertices, std::vector< std::vector<uint16_t>> indices);
		 
	private:
		int width{}, height{};
		//Instances Managers
		WindowsManager& m_windowsManager = WindowsManager::getInstance();
		RenderManager& m_renderManager = RenderManager::getInstance();
		ResourceManager& m_resourceManager = ResourceManager::getInstance();
	};
#endif // !GAME_ENGINE
}
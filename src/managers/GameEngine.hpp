#pragma once

#ifndef GAME_ENGINE
#define GAME_ENGINE

#include "../renderer/managers/WindowsManager.hpp"
#include "../renderer/managers/RenderManager.hpp"
#include "../renderer/managers/ResourceManager.hpp"
#include "../renderer/managers/InputManager.hpp"

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
		//bool IsScapeDown() const;
		bool IsKeyPressed(int key);
		bool IsKeyReleased(int key);
		bool IsKeyDown(int key);
		bool IsMouseButtomPressed(int buttom);
		bool IsMouseButtomDown(int buttom);

		//Renderer
		void beginFrame();
		void EndFrame();
		Camera* getCamera();
		//void setCameraPosition();
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
		InputManager& m_inputManager = InputManager::getInstance();
	};
#endif // !GAME_ENGINE
}
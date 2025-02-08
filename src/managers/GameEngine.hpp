#pragma once

#ifndef GAME_ENGINE
#define GAME_ENGINE

#include "../renderer/managers/WindowsManager.hpp"
#include "../renderer/managers/RenderManager.hpp"


namespace ENGI
{
	class GameEngine
	{
		//using u16 = std::uint16_t;
	public:
		GameEngine(int const width, int const height);
		/*~GameEngine()
		{
			delete camera;
		}*/
		//Time
		double GetTime() const;

		//Window
		bool InitWindow(int width, int height, const char* title);
		bool windowShouldClose() const;
		GLFWwindow* GetWindow() const;
		void CloseWindow() const;
		void UpdateViewport() const;
		
		//Input
		bool IsScapeDown() const;

		//Renderer
		void beginFrame();
		void EndFrame();
		//DRAW -> limpiar pantalla
		//void beginFrame();
		////DRAW -> termina dibujado
		//void endFrame();
		////FRAMERATE
		//double GetDeltaTime();
		////MOUSE
		//void SetCursorPos(double& mouse_x, double& mouse_y);
		////WINDOW
		//void InitWindow(int const width, int const height);
		//bool windowShouldClose();
		//void closeWindow();
		//GLFWwindow* getWindow() { return window; }
		//TEXTURES
		//void LoadTexture(const char* filename, TexturesType type);
		//void LoadTextureMap(const char* filename);
		//vec2f SetTexturetoEnt(std::size_t id, TexturesType type);
		//const ltex_t* GetTexture(size_t id);
		//const ltex_t* GetTextureMap();
		//TexturesType GetTextureType(size_t id);
		//unsigned char* getPixels(size_t id);
		//void unloadTextures();
		////FONTS
		//void LoadFont(const char* filename, float height, std::uint8_t type);
		//void drawFont(const char* text, vec2f& pos, std::uint8_t type);
		//float getWidth(std::uint8_t type);
		//void unloadFonts();
		////INPUTS
		//bool IsKeyPressed(int key);
		//bool IsKeyReleased(int key);
		//bool IsKeyDown(int key);
		//bool IsMouseButtomPressed(int buttom);
		//bool IsMouseButtomDown(int buttom);
		////CAMERA
		//const vec2f& getCameraPosition() const;
		//void setCameraPosition(const vec2f& pos);
		//void UpdateCamera(const vec2f& screenSize, const vec2f& levelSize, const vec2f& targetSprite);
	//public:
		////camera
		//SCamera* camera{};
	private:
		int width{}, height{};
		//vec2f cameraPos{};
		////Clear Colors
		//float clearRed, clearGreen, clearBlue;
		//// Managers
		//InputManager& m_inputManager = InputManager::getInstance();
		//TextureManager& m_textureManager = TextureManager::getInstance();
		//FontManager& m_fontManager = FontManager::getInstance();
		WindowsManager& m_windowsManager = WindowsManager::getInstance();
		RenderManager& m_renderManager = RenderManager::getInstance();
	};
#endif // !GAME_ENGINE
}
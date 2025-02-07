#pragma once

#include <GL/glew.h>
#include <glfw3.h>
#include <GL/gl.h>
#include <GL/glu.h>

class WindowsManager
{
public:
	bool InitWindow(int width, int height, const char* title);
	bool windowShouldClose() const;
	void closeWindow();

	GLFWwindow* getWindow() { return m_window; };
	int GetHeight() const { return m_height; }
	int GetWidth() const { return m_width; }

	void beginDrawing();
	void endDrawing();

	static WindowsManager& getInstance() {
		static WindowsManager instance;
		return instance;
	}

private:
	//window
	GLFWwindow* m_window{ nullptr };
	int m_width{ 0 }, m_height{ 0 };
};


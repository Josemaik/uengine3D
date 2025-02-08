#pragma once

#include "../components/Camera.hpp"
#include <memory>

class RenderManager
{
public:
	RenderManager() {}
	~RenderManager()
	{
		delete m_camera;
	}

	//Camera
	Camera* CreateCamera(glm::vec3 _position, glm::vec3 _origin, glm::vec3 _up);
	void setCamera(Camera* camera) { m_camera = camera; };
	Camera* getCamera() const { return m_camera; }
	void drawCamera() const { m_camera->draw(); }

	static RenderManager& getInstance() {
		static RenderManager instance;
		return instance;
	}
private:
	Camera* m_camera{};
};


#include "RenderManager.hpp"

Camera* RenderManager::CreateCamera(glm::vec3 _position, glm::vec3 _origin, glm::vec3 _up)
{

	m_camera = new Camera(_position,_origin,_up);
	if (m_camera) {
		return m_camera;
	}
	return nullptr;
}

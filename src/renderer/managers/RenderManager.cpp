#include "RenderManager.hpp"
#include "../resources/Shader.h"
#include "../resources/State.hpp"

Camera* RenderManager::CreateCamera(glm::vec3 _position, glm::vec3 _origin, glm::vec3 _up)
{

	m_camera = new Camera(_position,_origin,_up);
	if (m_camera) {
		return m_camera;
	}
	return nullptr;
}

void RenderManager::LoadShader()
{
	//Create Shaders
	Shader shader("../data/vertex.glsl", "../data/fragment.glsl");
	//Pasa a ser el Shader por defecto
	shader.AttachandLink();
	//Use Program
	shader.use();
	//Pasarlo como defaultshader
	State::defaultShader = std::make_shared<Shader>(shader);
}

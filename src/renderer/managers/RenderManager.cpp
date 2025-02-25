#include "RenderManager.hpp"
#include "ResourceManager.hpp"
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

const glm::vec3& RenderManager::getAmbient() const
{
	return State::ambient;
}

void RenderManager::setAmbient(const glm::vec3& _ambient)
{
	State::ambient = _ambient;
}

//void RenderManager::UpdateCamera()
//{
//	
//}

//void RenderManager::SetPositionCamera(glm::vec3 _position)
//{
//	m_camera->setPosition(_position);
//}

void RenderManager::LoadShader()
{
	auto& rmn = ResourceManager::getInstance();
	shaders["texture"] = rmn.loadResource<Shader>("shaderTexture", std::string("../data/vertex.glsl"),
		std::string("../data/fragment.glsl"));
	shaders["light"] = rmn.loadResource<Shader>("shaderLight", std::string("../data/vertex_light.glsl"),
		std::string("../data/fragment_light.glsl"));
	/*shaders["texture"] = rmn.loadResource<Shader>(std::string("../data/vertex.glsl"),
		std::string("../data/fragment.glsl"));*/
	/*int xd = 2;
	shaders["texture"] = rmn.loadResource<Shader>("xd",xd);*/

	//Create Shaders
	//Shader shader("../data/vertex.glsl", "../data/fragment.glsl");
	//shaders["texture"]->load();
	//Pasa a ser el Shader por defecto
	//shaders["texture"]->AttachandLink();
	////Use Program
	//shaders["texture"]->use();
	shaders["light"]->use();
	////Pasarlo como defaultshader
	State::defaultShader = std::make_shared<Shader>(*shaders["light"]);
}

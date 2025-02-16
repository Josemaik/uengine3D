#pragma once

#include "../../renderer/components/Model.hpp"
#include <vector>
#include <array>

struct RenderComponent
{
	//Data
	/*std::vector<Vertex> vertices =
	{
		Vertex(glm::vec3(-0.5f, -0.5f, 0.0f),glm::vec4(1.f,0.f,0.f,1.f)),
		Vertex(glm::vec3(0.5f, -0.5f, 0.0f),glm::vec4(0.f,0.f,1.f,1.f)),
		Vertex(glm::vec3(0.0f, 0.5f, 0.0f),glm::vec4(0.f,1.f,0.f,1.f))
	};
	std::array<uint16_t, 3> indices = { 0,1,2 };*/
	glm::vec3 position{ 0.f,0.f,0.f };
	glm::vec3 rotation{ 0.f,0.f,0.f };
	glm::vec3 scale{ 1.f,1.f,1.f };
	float angularvelocity{ 32.f };
	float currentangle{ 32.f };
	//Model
	Model* model{nullptr};
	//std::shared_ptr<Model> model;
};
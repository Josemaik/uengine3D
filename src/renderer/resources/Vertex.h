#pragma once

#include "../glm/vec3.hpp"
#include "../glm/vec4.hpp"

struct Vertex
{
	Vertex(glm::vec3 _position, glm::vec4 _color)
		:position(_position), color(_color)
	{
	}

	glm::vec3 position;
	glm::vec4 color;
};


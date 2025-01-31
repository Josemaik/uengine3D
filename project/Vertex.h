#pragma once

#include "../lib/glm/vec3.hpp"

struct Vertex
{
	Vertex(glm::vec3 _position)
		:position(_position)
	{
	}

	glm::vec3 position;
};


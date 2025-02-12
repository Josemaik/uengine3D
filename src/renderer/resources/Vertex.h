#pragma once

#include "../glm/vec3.hpp"
#include "../glm/vec4.hpp"
#include "../glm/vec2.hpp"

struct Vertex
{
	Vertex(glm::vec3 _position, glm::vec4 _color,glm::vec2 _textCord)
		:position(_position), color(_color), textureCord(_textCord)
	{
	}

	glm::vec3 position;
	glm::vec4 color;
	//Coordenadasd de textura
	glm::vec2 textureCord;
};


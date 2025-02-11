#pragma once

#include "../glm/vec2.hpp"
#include <GL/glew.h>

class Texture
{
public:
	Texture() = default;
	~Texture() 
	{
		///stbi_image_free();
	}

	bool load(const char* filename);
	uint32_t getId() const { return m_id; }
	const glm::ivec2& getSize() const;
	void bind() const;

	GLuint m_id;
	int m_width{}, m_height{};
};


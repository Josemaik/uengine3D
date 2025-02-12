#pragma once

#include "../glm/vec2.hpp"
#include <GL/glew.h>

class Texture
{
public:
	Texture(const char* _filepath)
	{
		filepath = _filepath;
	}
	~Texture()
	{
		///stbi_image_free();
	}

	bool load(const char* filename);
	uint32_t getId() const { return m_id; }
	const glm::ivec2& getSize() const;
	void bind() const;

	GLuint m_id{ 0 };
	int m_width{0}, m_height{0};
	const char* filepath = nullptr;
};


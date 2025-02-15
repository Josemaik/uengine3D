#pragma once
#include "Resource.hpp"
#include "../glm/vec2.hpp"
#include <GL/glew.h>

class Texture : public Resource
{
public:
	Texture(/*const char* _filepath*/)
	{
		//m_filepath = _filepath;
	}
	Texture(std::size_t id): m_id(id) {}
	~Texture()
	{
		unload();///stbi_image_free();
	}

	bool load(const char* filename) override;
	void unload() override;

	uint32_t getId() const { return m_id; }
	const glm::ivec2 getSize() const;
	void bind() const;
private:
	void setup() override;

	GLuint m_id{ 0 };
	int m_width{0}, m_height{0};
	//const char* filepath = nullptr;
};


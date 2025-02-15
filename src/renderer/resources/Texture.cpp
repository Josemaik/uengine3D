#include "Texture.hpp"
#include <glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

bool Texture::load(const char* filename)
{
	m_filepath = filename;
	setup();
	return isLoaded();
}

void Texture::unload()
{
	glDeleteTextures(1, &m_id);
	m_isLoad = false;
}

const glm::ivec2& Texture::getSize() const
{
	return glm::ivec2(m_width, m_height);
}

void Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, m_id);
}

void Texture::setup()
{
	//GLFWimage images[1]{};
	stbi_uc* bufferpixels = nullptr;
	//buffer que almacena los datos de la imágen
	bufferpixels = stbi_load(m_filepath.c_str(), &m_width, &m_height, 0, 4);
	if (bufferpixels)
	{
		//Generamos textura
		//GLuint textId;
		glGenTextures(1, &m_id);
		//Activate
		glBindTexture(GL_TEXTURE_2D, m_id);
		//Parameters
		//// Set the texture wrapping parameters
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		//Load image
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, static_cast<GLsizei>(m_width),
			static_cast<GLsizei>(m_height), 0, GL_RGBA, GL_UNSIGNED_BYTE, bufferpixels);
		//// Set texture filtering parameters
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, 3); //filtrado trilineal

		glGenerateMipmap(GL_TEXTURE_2D);

		m_isLoad = true;
	}
	//Free buffer
	stbi_image_free(bufferpixels);
}

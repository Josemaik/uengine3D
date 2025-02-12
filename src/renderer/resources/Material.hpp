#pragma once

#include "Texture.hpp"
#include "Shader.h"
#include <memory>

class Material
{
public:
	Material(const std::shared_ptr<Texture>& tex = nullptr, const std::shared_ptr<Shader>& shader = nullptr)
		:m_texture(tex),m_shader(shader)
	{
	}
	~Material() {}

	const std::shared_ptr<Shader>& getShader() const;
	const std::shared_ptr<Texture>& getTexture() const { return m_texture; }
	//std::shared_ptr<Shader>& getShader() { return m_shader; }
	void setShader(const std::shared_ptr<Shader>& shader);
	void setTexture(const std::shared_ptr<Texture>& tex);

	void prepare() const;

	std::shared_ptr<Texture> m_texture;
	std::shared_ptr<Shader> m_shader;
};
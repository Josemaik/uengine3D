#pragma once

#include "Resource.hpp"

#include "Texture.hpp"
#include "Shader.h"
#include <memory>

class Material : public Resource
{
public:
	Material(std::size_t id) { m_id = id; m_texture = nullptr; }
	/*Material(std::size_t id,const std::shared_ptr<Texture>& tex = nullptr, const std::shared_ptr<Shader>& shader = nullptr)
		:m_texture(tex),m_shader(shader)
	{
		m_id = id;
	}*/
	~Material() {}

	bool load(const char* filepath) override;
	void unload() override;

	const std::shared_ptr<Shader>& getShader() const;
	const Texture* getTexture() const { return m_texture; }
	//std::shared_ptr<Shader>& getShader() { return m_shader; }
	void setShader(const std::shared_ptr<Shader>& shader);
	void setTexture(Texture* text);

	void prepare() const;

private:
	//std::shared_ptr<Texture> m_texture;
	Texture* m_texture = nullptr;
	std::shared_ptr<Shader> m_shader;
};
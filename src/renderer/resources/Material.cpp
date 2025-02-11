#include "Material.hpp"
#include "State.hpp"

const std::shared_ptr<Shader>& Material::getShader() const
{
	if (m_shader)
	{
		return m_shader;
	}
	return State::defaultShader;
}

void Material::setShader(const std::shared_ptr<Shader>& shader)
{
	m_shader = shader;
}

void Material::setTexture(const std::shared_ptr<Texture>& tex)
{
	m_texture = tex;
}

void Material::prepare()
{
	//Active Shader
	const std::shared_ptr<Shader>& currentShader = getShader();
	currentShader->use();
	//Write uniform
	glm::mat4 mvp = State::projectionMatrix * State::viewMatrix * State::modelMatrix;
	GLint uniMVP = glGetUniformLocation(currentShader->getID(), "mvp");
	currentShader->setMatrix(uniMVP, mvp);
	//Bindear Textura
	if (m_texture)
	{
		//set true to draw texture
		GLint usetextureloc = glGetUniformLocation(currentShader->getID(), "drawTexture");
		currentShader->setInt(usetextureloc, GL_FALSE); //GL_TRUE-> dibujar textura
		//bind texture
		m_texture->bind();
		//set texSampler
		currentShader->setInt(currentShader->getLocation("texSampler"), 0);
	}
}

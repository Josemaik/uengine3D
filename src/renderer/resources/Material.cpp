#include "Material.hpp"
#include "State.hpp"

bool Material::load(const char* filepath)
{
	m_filepath = filepath;
	m_isLoad = true;
	return isLoaded();
}

void Material::unload()
{
	m_isLoad = false;
	printf("Unload Material\n");
}

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

void Material::setTexture(Texture* text)
{
	m_texture = text;
}

void Material::prepare() const
{
	//Active Shader
	const std::shared_ptr<Shader>& currentShader = getShader();
	currentShader->use();
	//Write uniform
	//glm::mat4 mvp = State::projectionMatrix * State::viewMatrix * State::modelMatrix;
	GLint locmodel = glGetUniformLocation(currentShader->getID(), "model");
	currentShader->setMatrix(locmodel, State::modelMatrix);
	GLint locview = glGetUniformLocation(currentShader->getID(), "view");
	currentShader->setMatrix(locview, State::viewMatrix);
	GLint locproj = glGetUniformLocation(currentShader->getID(), "projection");
	currentShader->setMatrix(locproj, State::projectionMatrix);
	//Bindear Textura
	if (m_texture)
	{
		// Indicar al shader que use la textura
		GLint usetextureloc = glGetUniformLocation(currentShader->getID(), "drawTexture");
		currentShader->setInt(usetextureloc, GL_TRUE);

		// bind
		m_texture->bind();

		// Asignar la textura al sampler
		GLint texsamplerloc = glGetUniformLocation(currentShader->getID(), "texSampler");
		currentShader->setInt(texsamplerloc, 0);
	}
}

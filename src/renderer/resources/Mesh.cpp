#include "Mesh.hpp"
#include "State.hpp"

Mesh::Mesh(std::size_t id, shared_buffer buffer, Material* material)
{
	m_id = id;
	addBuffer(buffer,*material);
	//name
}

bool Mesh::load(const char* filepath)
{
	m_isLoad = true;
	return isLoaded();
}

void Mesh::unload()
{
	m_isLoad = false;
	printf("Unload mesh\n");
}

void Mesh::addBuffer(shared_buffer buffer, const Material& material)
{
	//Vec_Buffers.emplace_back(std::make_pair(buffer, shader));
	if (buffer)
	{
		buffers.push_back(buffer);
		//printf("Buffer agregado. Total ahora: %d", getNumBuffers());
	}
	materials.push_back(material);
	//shaders.push_back(shader ? shader : State::defaultShader);
}

size_t Mesh::getNumBuffers() const
{
	//return Vec_Buffers.size();
	return buffers.size();
}

shared_buffer Mesh::getBuffer(size_t index) const
{
	//return Vec_Buffers.at(index).first;
	return buffers.at(index);
}

const Material& Mesh::getMaterial(size_t index) const
{
	return materials.at(index);
}

Material& Mesh::getMaterial(size_t index)
{
	return materials.at(index);
}

void Mesh::draw()
{
	//mvp
	//glm::mat4 mvp = State::projectionMatrix * State::viewMatrix * State::modelMatrix;

	for (size_t i = 0; i < buffers.size(); ++i) {
		/*GLint uniMVP = glGetUniformLocation(shaders[i]->getID(), "mvp");
		shaders[i]->setMatrix(uniMVP, mvp);*/
		materials[i].prepare();
		Shader& shader = *materials[i].getShader();
		buffers[i]->draw(shader);

		shader.use();
	}
}

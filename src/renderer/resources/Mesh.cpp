#include "Mesh.hpp"
#include "State.hpp"

void Mesh::addBuffer(shared_buffer buffer, shared_shader shader)
{
	//Vec_Buffers.emplace_back(std::make_pair(buffer, shader));
	if (buffer)
	{
		buffers.push_back(buffer);
		printf("Buffer agregado. Total ahora: %d", getNumBuffers());
	}
	
	shaders.push_back(shader ? shader : State::defaultShader);
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

void Mesh::draw()
{
	//mvp
	glm::mat4 mvp = State::projectionMatrix * State::viewMatrix * State::modelMatrix;

	for (size_t i = 0; i < buffers.size(); ++i) {
		GLint uniMVP = glGetUniformLocation(shaders[i]->getID(), "mvp");
		shaders[i]->setMatrix(uniMVP, mvp);

		buffers[i]->draw(*shaders[i]);

		shaders[i]->use();
	}
}

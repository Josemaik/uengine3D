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
		//if (shaders[i]) {
		//	/*shaders[i]->bind();*/
		//}
		//else {
		//	/*State::defaultShader->bind();*/

		//}
		GLint uniMVP = glGetUniformLocation(shaders[i]->getID(), "mvp");
		shaders[i]->setMatrix(uniMVP, mvp);

		// Calcular la matriz MVP
		//glm::mat4 MVP = State::projectionMatrix * State::viewMatrix * State::modelMatrix;
		//shaders[i]->setMatrix("MVP", MVP);

		buffers[i]->draw(*shaders[i]);

		shaders[i]->use();
	}
	/*for (auto& buffer : Vec_Buffers)
	{*/
		//mvp
		

		//Shader* shared_shader = buffer.second.get();
		// Verificar si la dirección de memoria es basura
		//if (m_shader.get() != reinterpret_cast<Shader*>(0xCCCCCCCC)/*shared_shader != reinterpret_cast<Shader*>(0xCCCCCCCC)*/)
		//{
		//	//si es una dirección válida
		//	//set mvp
		//	GLint uniMVP = glGetUniformLocation(m_shader.get()->getID()/*shared_shader->getID()*/, "mvp");
		//	/*shared_shader*/m_shader->setMatrix(uniMVP, mvp);
		//	//draw mesh
		//	/*buffer.first.get()*/m_buffer->draw(*m_shader/*shared_shader*/);

		//	/*shared_shader*/m_shader->use();

		//	//continue;
		//}
		//Default Shader
		//set mvp
		//GLint uniMVP = glGetUniformLocation(State::defaultShader->getID(), "mvp");
		//State::defaultShader->setMatrix(uniMVP, mvp);
		////Draw mesh
		///*buffer.first.get()*/m_buffer->draw(*State::defaultShader);

		//State::defaultShader->use();
	//}
}

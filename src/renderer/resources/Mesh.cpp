#include "Mesh.hpp"
#include "State.hpp"

void Mesh::addBuffer(shared_buffer buffer, shared_shader shader)
{
	Vec_Buffers.push_back(std::make_pair(buffer, shader));
}

size_t Mesh::getNumBuffers() const
{
	return Vec_Buffers.size();
}

shared_buffer Mesh::getBuffer(size_t index) const
{
	return Vec_Buffers.at(index).first;
}

void Mesh::draw()
{
	for (auto& buffer : Vec_Buffers)
	{
		auto* shared_shader = buffer.second.get();
		if (shared_shader != nullptr)
		{
			buffer.first.get()->draw(*shared_shader);
		}
		buffer.first.get()->draw(*State::defaultShader);
	}
}

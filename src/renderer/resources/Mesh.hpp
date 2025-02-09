#pragma once

#include <memory>
#include <utility>
#include "Buffer.h"

using shared_buffer = const std::shared_ptr<Buffer>&;
using shared_shader = const std::shared_ptr<Shader>&;

class Mesh
{
public:
	~Mesh()
	{
		printf("Se destruye Mesh\n");
	}
	//Add new buffer
	void addBuffer(shared_buffer buffer, shared_shader shader = nullptr);

	size_t getNumBuffers() const;

	shared_buffer getBuffer(size_t index) const;

	void draw();

	//std::vector< std::pair<shared_buffer, shared_shader> > Vec_Buffers;
	std::vector<std::shared_ptr<Buffer>> buffers;
	std::vector<std::shared_ptr<Shader>> shaders;
};


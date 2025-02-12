#pragma once

#include <memory>
#include <utility>
#include "Buffer.h"
#include "Material.hpp"

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
	void addBuffer(shared_buffer buffer, const Material& material);

	size_t getNumBuffers() const;

	shared_buffer getBuffer(size_t index) const;

	const Material& getMaterial(size_t index) const;
	Material& getMaterial(size_t index);

	void draw();

	//std::vector< std::pair<shared_buffer, shared_shader> > Vec_Buffers;
	std::vector<std::shared_ptr<Buffer>> buffers;
	//std::vector<std::shared_ptr<Shader>> shaders;
	std::vector<Material> materials;
};


#pragma once

#include "Entity.hpp"
#include "../resources/Mesh.hpp"
#include <memory>

class Model : public Renderer::Entity
{
public:
	Model(const std::shared_ptr<Mesh>& _mesh) :
		mesh(_mesh)
	{}

	const std::shared_ptr<Mesh>& getMesh() const { return mesh; }

	void draw() override;
private:
	const std::shared_ptr<Mesh>& mesh;
};


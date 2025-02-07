#pragma once

#include "Entity.hpp"
#include "../resources/Mesh.hpp"
#include <memory>

class Model : public Entity
{
public:
	Model(const std::shared_ptr<Mesh>& _mesh) :
		mesh(_mesh)
	{}

	void draw() override;
private:
	const std::shared_ptr<Mesh>& mesh{};
};


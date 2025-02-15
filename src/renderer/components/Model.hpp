#pragma once

#include "Entity.hpp"
#include "../resources/Mesh.hpp"
#include <memory>

class Model : public Renderer::Entity
{
public:
	Model(Mesh* _mesh) :
		mesh(_mesh)
	{}
	~Model()
	{
		delete mesh;
		mesh = nullptr;
	}

	Mesh* getMesh() const { return mesh; }

	void draw() override;
private:
	//const std::shared_ptr<Mesh>& mesh;
	Mesh* mesh;
};


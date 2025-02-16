#pragma once

#include "../ECS/types.hpp"

class EntityFactory
{
public:
	void CreateTriangles(EntityManager& em);
	void CreateCube(EntityManager& em);
	void CreateBoxStack(EntityManager& em);
	void CreateGunSlinger(EntityManager& em);
};


#pragma once

#include "../types.hpp"

class RenderSystem
{
	using CmpsList = MP::TypeList<RenderComponent>;
	using TagList = MP::TypeList<>;

public:
	void update(EntityManager& em, float Deltatime);
	void Init();
	void UnloadModels(EntityManager& em);
};
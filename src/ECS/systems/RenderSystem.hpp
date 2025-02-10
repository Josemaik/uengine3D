#pragma once

#include "../types.hpp"

class RenderSystem
{
	using CmpsList = MP::TypeList<RenderComponent>;
	using TagList = MP::TypeList<>;

public:
	void update(EntityManager& em, float Deltatime);
	void LoadModels(EntityManager& em,GameEngine& ge);
	void UnloadModels(EntityManager& em);
};
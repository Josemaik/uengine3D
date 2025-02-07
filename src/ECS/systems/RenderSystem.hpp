#pragma once

#include "../types.hpp"

class RenderSystem
{
	using CmpsList = MP::TypeList<RenderComponent>;
	using TagList = MP::TypeList<>;

	void update();
	void Init();
};
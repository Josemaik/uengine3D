#pragma once

#include "Entity.hpp"
#include "../resources/Shader.h"
#include <memory>

enum class Type
{
	DIRECTIONAL,
	POINT
};

class Light : public Renderer::Entity
{
public:
	Type getType() const{ return type; }
	void setType(Type type);

	const glm::vec3& getColor() const { return color; };
	void setColor(const glm::vec3& color);

	float getLinearAttenuation(float att) { return LinearAttenuation; }
	void setLinearAttenuation(float att);

	void prepare(int index, std::shared_ptr<Shader>& shader) const;
private:
	Type type;
	glm::vec3 color;
	float LinearAttenuation{ 1.f };
};


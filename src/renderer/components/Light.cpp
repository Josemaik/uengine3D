#include "Light.hpp"

void Light::setType(Type _type)
{
	type = _type;
}

void Light::setColor(const glm::vec3& _color)
{
	color = _color;
}

void Light::setLinearAttenuation(float att)
{
	LinearAttenuation = att;
}

void Light::prepare(int index, std::shared_ptr<Shader>& shader) const
{

}

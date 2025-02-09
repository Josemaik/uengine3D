#include "Entity.hpp"

const glm::vec3& Renderer::Entity::getPosition() const
{
  return position;
}

void Renderer::Entity::setPosition(const glm::vec3& pos)
{
  position = pos;
}

const glm::quat& Renderer::Entity::getRotation() const
{
  return rotation;
}

//float Renderer::Entity::getAngle() const
//{
//  return angle;
//}

const void Renderer::Entity::setRotation(const glm::quat& rot)
{
  rotation = rot;
}

const glm::vec3& Renderer::Entity::getScale() const
{
  return scale;
}

void Renderer::Entity::setScale(const glm::vec3& _scale)
{
  scale = _scale;
}

void Renderer::Entity::move(const glm::vec3& vec)
{
}

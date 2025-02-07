#include "Entity.hpp"

const glm::vec3& Entity::getPosition() const
{
  return position;
}

void Entity::setPosition(const glm::vec3& pos)
{
  position = pos;
}

const glm::vec3& Entity::getRotation() const
{
  return rotation;
}

float Entity::getAngle() const
{
  return angle;
}

const void Entity::setRotation(const glm::vec3& rot)
{
  rotation = rot;
}

const glm::vec3& Entity::getScale() const
{
  return scale;
}

void Entity::setScale(const glm::vec3& _scale)
{
  scale = _scale;
}

void Entity::move(const glm::vec3& vec)
{
}

#include "Camera.hpp"
#include "../resources/State.hpp"
#include <gtc/matrix_transform.hpp>

const glm::mat4& Camera::getProjection() const
{
  return cameraProjection;
}

void Camera::setProjection(const glm::mat4& proj)
{
  cameraProjection = proj;
}

const glm::ivec4& Camera::getViewport() const
{
  return viewport;
}

void Camera::setViewport(const glm::ivec4& vp)
{
  viewport = vp;
}

const glm::vec3& Camera::getClearColor() const
{
  return clearColor;
}

void Camera::setClearColor(const glm::vec3& color)
{
  clearColor = color;
}

const glm::vec3& Camera::getOrigin() const
{
  return origin;
}

const glm::vec3& Camera::getUp() const
{
  return up;
}

const float Camera::getSpeed() const
{
  return speed;
}

void Camera::draw()
{
  prepare();
}

void Camera::prepare()
{
  State::projectionMatrix = cameraProjection;

  State::viewMatrix = glm::lookAt(
    getPosition(), //eye
    getPosition() + origin, //center
    up); //up

  glViewport(viewport.x,viewport.y,viewport.z,viewport.w);
  glScissor(viewport.x, viewport.y, viewport.z, viewport.w);

  glClearColor(clearColor.x, clearColor.y, clearColor.z, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


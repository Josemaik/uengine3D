#pragma once

#include "Entity.hpp"
#include "../glm/mat4x4.hpp"

class Camera : public Entity
{
	Camera(glm::vec3 _position, glm::vec3 _origin, glm::vec3 _up):
		position(_position),origin(_origin),up(_up)
	{}
	~Camera() {}

	const glm::mat4& getProjection() const;
	void setProjection(const glm::mat4& proj);
	const glm::ivec4& getViewport() const;
	void setViewport(const glm::ivec4& vp);
	const glm::vec3& getClearColor() const;
	void setClearColor(const glm::vec3& color);
	void prepare();


private:
	// Camera Attributes
	glm::vec3 position{ 1.0f, 1.0f, 1.0f };
	glm::vec3 origin{ 0.0f, 0.0f, 0.0f };
	glm::vec3 up{ 0.0f, 1.0f, 0.0f };

	glm::ivec4 viewport{ 0.f, 0.f, 0.f, 0.f };

	glm::vec3 clearColor{};

	glm::mat4 cameraProjection{};

};
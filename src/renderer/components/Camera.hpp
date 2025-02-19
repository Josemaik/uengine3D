#pragma once

#include "Entity.hpp"
#include "../glm/mat4x4.hpp"

class Camera : public Renderer::Entity
{
public:
	Camera(glm::vec3 _position, glm::vec3 _origin, glm::vec3 _up):
		origin(_origin),up(_up)
	{
		setPosition(_position);
	}
	~Camera() noexcept{ printf("Camera destroyed\n"); }

	const glm::mat4& getProjection() const;
	void setProjection(const glm::mat4& proj);
	const glm::ivec4& getViewport() const;
	void setViewport(const glm::ivec4& vp);
	const glm::vec3& getClearColor() const;
	void setClearColor(const glm::vec3& color);
	const glm::vec3& getOrigin() const;
	const glm::vec3& getUp() const;
	const float getSpeed() const;
	void draw() override;
	void prepare();

private:
	// Camera Attributes
	///glm::vec3 position{ 1.0f, 1.0f, 1.0f };
	glm::vec3 eye{ 30.f,0.f,0.f };
	glm::vec3 origin{ 0.0f, 0.0f, -1.0f };
	glm::vec3 up{ 0.0f, 1.0f, 0.0f };
	float speed{ 10.f };
	glm::ivec4 viewport{ 0.f, 0.f, 0.f, 0.f };

	glm::vec3 clearColor{};

	glm::mat4 cameraProjection{};

};
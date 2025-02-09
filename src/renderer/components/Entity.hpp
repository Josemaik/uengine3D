#pragma once

#include "../glm/vec3.hpp"
#include "../glm/gtc/quaternion.hpp"

namespace Renderer {
	class Entity
	{
	public:
		Entity() {};
		virtual	~Entity() {};

		const glm::vec3& getPosition() const;
		void setPosition(const glm::vec3& pos);
		const glm::quat& getRotation() const; //quat
		//float getAngle() const;
		const void setRotation(const glm::quat& rot); //quat
		const glm::vec3& getScale() const;
		void setScale(const glm::vec3& scale);
		void move(const glm::vec3& vec); //Ver diapos
		virtual void update(float deltaTime) {}
		virtual void draw() {}
	private:
		glm::vec3 position{};
		glm::quat rotation{}; //Axis
		//float angle{ 0.f };
		glm::vec3 scale{};
	};
};



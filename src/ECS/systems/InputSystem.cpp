#include "InputSystem.hpp"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/vec3.hpp"
#include "glm/glm.hpp"

#include "../../renderer/resources/State.hpp"

void InputSystem::update(GameEngine& ge)
{
	const float cameraspeed = 0.1f;
	//Update Camera
	if (ge.IsKeyDown(GLFW_KEY_UP))
	{
		auto* camera = ge.getCamera();
		auto pos = camera->getPosition();
		//pos.x--;
		pos += cameraspeed * glm::vec3(0.f, 0.f, -1.f);
		ge.getCamera()->setPosition(pos);
		//glm:: State::viewMatrix
		//State::viewMatrix = glm::translate(State::viewMatrix, glm::vec3(-1.f, 0.f, 0.f));
	}
	if (ge.IsKeyDown(GLFW_KEY_DOWN))
	{
		//State::viewMatrix = glm::translate(State::viewMatrix, glm::vec3(1.f, 0.f, 0.f));
		auto* camera = ge.getCamera();
		auto pos = camera->getPosition();
		//pos.x++;
		pos -= cameraspeed * glm::vec3(0.f, 0.f, -1.f);
		ge.getCamera()->setPosition(pos);
		//glm::tra
	}
	if (ge.IsKeyDown(GLFW_KEY_LEFT))
	{
		auto* camera = ge.getCamera();
		auto pos = camera->getPosition();
		//pos.y--;
		pos -= glm::normalize(glm::cross(glm::vec3(0.f, 0.f, -1.f), glm::vec3(0.f, 1.f, 0.f))) * cameraspeed;
		ge.getCamera()->setPosition(pos);
	}
	if (ge.IsKeyDown(GLFW_KEY_RIGHT))
	{
		auto* camera = ge.getCamera();
		auto pos = camera->getPosition();
		//pos.y++;
		pos += glm::normalize(glm::cross(glm::vec3(0.f, 0.f, -1.f), glm::vec3(0.f, 1.f, 0.f))) * cameraspeed;
		ge.getCamera()->setPosition(pos);
	}
}

#include "InputSystem.hpp"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/vec3.hpp"
#include "glm/glm.hpp"

#include "../../renderer/resources/State.hpp"

void InputSystem::update(GameEngine& ge, float DeltaTime)
{
	//setup variables
	auto* camera = ge.getCamera();
	float cameraspeed = camera->getSpeed() * DeltaTime;
	auto pos = camera->getPosition();
	auto OriginVec = camera->getOrigin();
	auto UpVec = camera->getUp();
	//Update Camera position
	if (ge.IsKeyDown(GLFW_KEY_UP))
	{	
		pos += cameraspeed * OriginVec;
	}
	if (ge.IsKeyDown(GLFW_KEY_DOWN))
	{
		pos -= cameraspeed * OriginVec;
	}
	if (ge.IsKeyDown(GLFW_KEY_LEFT))
	{
		pos -= glm::normalize(glm::cross(OriginVec, UpVec)) * cameraspeed;
	}
	if (ge.IsKeyDown(GLFW_KEY_RIGHT))
	{
		pos += glm::normalize(glm::cross(OriginVec, UpVec)) * cameraspeed;
	}
	//set position
	camera->setPosition(pos);
}

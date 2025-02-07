#include "Model.hpp"
#include "../resources/State.hpp"
#include <gtc/matrix_transform.hpp>
#include <gtc/quaternion.hpp>
#include <gtc/type_ptr.hpp>

void Model::draw()
{
	glm::mat4 translationMatrix = glm::translate(glm::mat4(), getPosition());
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(1), getScale());
	//glm::mat4 rotationMatrix = glm::rotate(getAngle(), getRotation());
	glm::quat rotation = glm::angleAxis(glm::radians(getAngle()), getRotation());

	State::modelMatrix = translationMatrix * glm::mat4_cast(rotation) * scaleMatrix;

	//LLamamos a dibujar la malla
	if(mesh)
		mesh->draw();
}

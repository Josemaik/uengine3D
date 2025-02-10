#include "Model.hpp"
#include "../resources/State.hpp"
#include <gtc/matrix_transform.hpp>
#include <gtc/quaternion.hpp>
#include <gtc/type_ptr.hpp>

void Model::draw()
{
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.f), getPosition());
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.f), getScale());
	//glm::mat4 rotationMatrix = glm::rotate(getAngle(), getRotation());
	glm::quat rotation = getRotation(); //glm::angleAxis(glm::radians(getAngle()), getRotation());

	State::modelMatrix = translationMatrix * glm::mat4_cast(rotation); //* scaleMatrix;
	
	//LLamamos a dibujar la malla
	if(mesh)
		mesh->draw();
}

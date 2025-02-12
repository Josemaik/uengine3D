#include "Buffer.h"

void Buffer::draw(const Shader& shader) const
{
	//VBO y EBO vinculados
	glBindBuffer(GL_ARRAY_BUFFER, m_ids[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ids[1]);
	//Atributos del shader
	shader.setupAttribs();

	glDrawElements(GL_TRIANGLES, num_indices, GL_UNSIGNED_SHORT, nullptr);
}

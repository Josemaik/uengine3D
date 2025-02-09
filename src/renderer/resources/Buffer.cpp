#include "Buffer.h"

void Buffer::draw(const Shader& shader) const
{
	/*glBindVertexArray(m_vao);

	shader.setupAttribs();

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glBindVertexArray(0);*/
	//VBO y EBO vinculados
	glBindBuffer(GL_ARRAY_BUFFER, m_ids[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ids[1]);
	//Atributos del shader
	shader.setupAttribs();

	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, nullptr);
	// Desactivamos los atributos después de dibujar
	/*glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);*/
	// Desvinculamos los buffers
	/*glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);*/
}

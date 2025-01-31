#include "Buffer.h"

void Buffer::draw(const Shader& shader) const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_ids[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ids[1]);

	shader.setupAttribs();

	GLsizei size = static_cast<GLsizei>(m_ids.size());
	glDrawElements(GL_TRIANGLES,size, GL_UNSIGNED_SHORT, nullptr);
}

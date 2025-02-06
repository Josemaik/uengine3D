#pragma once


//#include <GL/glew.h>

#include "Vertex.h"
#include <array>
#include <vector>
#include "Shader.h"

class Buffer
{
public:
	Buffer(std::vector<Vertex> vertices, std::array<uint16_t, 6> indices)
	{
		//unsigned int vao; // vertex array object
		//glGenVertexArrays(1, &m_vao);

		////unsigned int vbo;
		//glGenBuffers(1, &m_vbo);

		//glBindVertexArray(m_vao); // se guardan configuraciones que haga

		//glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<const
		//	void*>(offsetof(Vertex, position)));// 3 * sizeof(float)(void*)0

		//glEnableVertexAttribArray(0);

		//glBindVertexArray(0);
		//Generamos buffers y colocamos identificadores
		glGenBuffers(2, m_ids.data());
		//Establecemos el buffer activo
		glBindBuffer(GL_ARRAY_BUFFER, m_ids[0]);//vertex info
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ids[1]);//index of vertex
		//Enviamos datos al buffer
		glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizei>(sizeof(Vertex) * vertices.size()), vertices.data(), GL_STATIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast <GLsizei>(sizeof(uint16_t) * indices.size()), indices.data(), GL_STATIC_DRAW);
	}
	~Buffer()
	{
		glDeleteBuffers(2, m_ids.data());
	}

	void draw(const Shader& shader) const;

	//std::array<uint16_t, 2> index_buffer;
	//std::array<Vertex, 2> vertex_buffer;
	std::array<uint32_t, 2> m_ids;
	/*unsigned int m_vao;
	unsigned int m_vbo;*/
};


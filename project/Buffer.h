#pragma once


#include <GL/glew.h>
#include "Vertex.h"
#include <array>
#include <vector>
#include "Shader.h"

std::vector<Vertex> vértices = {
 Vertex(glm::vec3(0, 0.5f, 0)),
 Vertex(glm::vec3(-0.5f, -0.5f, 0)),
 Vertex(glm::vec3(0.5f, -0.5f, 0))
};

struct Buffer
{
	Buffer(std::vector<Vertex> vertices, std::array<uint16_t, 3> indices)
	{
		//Generamos buffers y colocamos identificadores
		glGenBuffers(2, m_ids.data());
		//Establecemos el buffer activo
		glBindBuffer(GL_ARRAY_BUFFER, m_ids[0]);//vertex info
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ids[1]);//index of vertex
		//Enviamos datos al buffer
		glBufferData(GL_ARRAY_BUFFER,sizeof(Vertex) * vertices.size(), vertices.data(),GL_STATIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint16_t) * indices.size(), indices.data(),GL_STATIC_DRAW);
	}
	~Buffer()
	{
		glDeleteBuffers(2, m_ids.data());
	}

	void draw(const Shader& shader) const;

	//std::array<uint16_t, 2> index_buffer;
	//std::array<Vertex, 2> vertex_buffer;
	std::array<uint32_t, 2> m_ids;
};


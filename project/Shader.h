#pragma once

#include <cstdint>
#include "../lib/glm/vec3.hpp"
#include "../lib/glm/vec4.hpp"
#include "../lib/glm/mat4x4.hpp"
#include "../lib/glew/GL/glew.h"

struct Shader
{
	Shader(GLuint _vertex_shader,GLuint _fragment_shader)
		:vertexShader(_vertex_shader),fragmentShader(_fragment_shader)
	{
		idProgram = glCreateProgram();
	}
	~Shader()
	{
		printf("Shader destruido\n");
	}

	uint32_t getID() const;
	const char* getError() const;
	void use() const;
	void setupAttribs() const;
	int getLocation(const char* name) const;

	void setInt(int loc, int val);
	void setFloat(int loc, float val);
	void setVec3(int loc, const glm::vec3& vec);
	void setVec4(int loc, const glm::vec4& vec);
	void setMatrix(int loc, const glm::mat4& matrix);

	//Ids
	GLuint idProgram{};
	GLuint vertexShader{};
	GLuint fragmentShader{};
	//Errores
	const char* error_vertex_shader{};
	const char* error_fragment_shader{};
	const char* error_link_program{};
	//Atribute

};


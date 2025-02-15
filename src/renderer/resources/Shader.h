#pragma once

#include "Resource.hpp"

#include <cstdint>
#include <vector>
#include <string>

#include <GL/glew.h>
#include "../glm/vec4.hpp"
#include "../glm/vec3.hpp"
#include "../glm/mat4x4.hpp"

class Shader : public Resource
{
public:
	/*Shader(GLuint _vertex_shader, GLuint _fragment_shader)
		:vertexShader(_vertex_shader), fragmentShader(_fragment_shader)
	{
		idProgram = glCreateProgram();
	}*/
	//Shader(std::size_t id, const char* _vertex_path = "", const char* _fragment_path = "");
	Shader(std::size_t id,std::string _vertexpath, std::string _fragmentshader) 
	{ 
		m_id = id; 
		m_vertexPath = _vertexpath;
		m_fragmentPath = _fragmentshader;
	}
	//Shader(std::size_t id, std::string vertexPath, std::string fragmentPath);
	~Shader()
	{
		unload();
	}

	bool load(const char* filePath) override;
	void unload() override;

	void AttachandLink();
	void use() const;
	void setupAttribs() const;

	uint32_t getID() const;
	const char* getError(int index) const;
	std::vector<const char*> getErrors() const;
	int getLocation(const char* name) const;

	void setInt(int loc, int val);
	void setFloat(int loc, float val);
	void setVec3(int loc, const glm::vec3& vec);
	void setVec4(int loc, const glm::vec4& vec);
	void setMatrix(int loc, const glm::mat4& matrix);
private:
	void setup() override;
	//Ids
	GLuint idProgram{};
	GLuint vertexShader{};
	GLuint fragmentShader{};
	//Errores
	std::vector<const char*> vec_errors;

	std::string m_vertexPath;
	std::string m_fragmentPath;
	/*const char* error_vertex_shader{};
	const char* error_fragment_shader{};
	const char* error_link_program{};*/
	//Atribute

};


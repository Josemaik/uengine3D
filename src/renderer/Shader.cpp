#include "Shader.h"
#include "Vertex.h"

#include <iostream>
using namespace std;

uint32_t Shader::getID() const
{
  return idProgram;
}

const char* Shader::getError(int index) const
{
  return vec_errors.at(index);
}

std::vector<const char*> Shader::getErrors() const
{
  return vec_errors;
}

void Shader::AttachandLink()
{
  glAttachShader(getID(), vertexShader);
  glAttachShader(getID(), fragmentShader);
  //Enlazar shaders
  glLinkProgram(getID());

  int succes;
  glGetShaderiv(getID(), GL_LINK_STATUS, &succes);
  if (!succes) {
    char errorLog[1024];
    glGetShaderInfoLog(fragmentShader, sizeof(errorLog), nullptr, errorLog);
    std::cout << "Error link";
  }

  //Borrar shaders
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}


void Shader::use() const
{
  //Usar el programa
  glUseProgram(idProgram);
}

void Shader::setupAttribs() const
{
  //Vertex Shader
  GLint location_vpos = glGetAttribLocation(idProgram, "vpos");
  GLint location_vcolor = glGetAttribLocation(idProgram, "vcolor");
  if (location_vpos != -1)
  {
    //Activar escritura
    glEnableVertexAttribArray(location_vpos);
    //Especificar formato
    glVertexAttribPointer(location_vpos, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<const
      void*>(offsetof(Vertex, position)));
  }
  if (location_vcolor != -1)
  {
    //Activar escritura
    glEnableVertexAttribArray(location_vcolor);
    //Especificar formato
    glVertexAttribPointer(location_vcolor, 4, GL_FLOAT, false, sizeof(Vertex), reinterpret_cast<const
      void*>(offsetof(Vertex, color)));
  }
  /*GLint location_mvp = glGetAttribLocation(idProgram, "mvp");
  if (location_mvp != -1)
  {
    const glm::mat4 matrix = glm::mat4();
    setMatrix(location_mvp, matrix);
  }*/
}

int Shader::getLocation(const char* name) const
{
  return glGetUniformLocation(idProgram, name);
}

void Shader::setInt(int loc, int val)
{
  if (loc != -1)
    glUniform1i(loc, val);
}

void Shader::setFloat(int loc, float val)
{
  if (loc != -1)
    glUniform1f(loc, val);
}

void Shader::setVec3(int loc, const glm::vec3& vec)
{
  if (loc != -1)
    glUniform3f(loc, vec.x, vec.y, vec.z);
}

void Shader::setVec4(int loc, const glm::vec4& vec)
{
  if (loc != -1)
    glUniform4f(loc, vec.x, vec.y, vec.z, vec.w);
}

void Shader::setMatrix(int loc, const glm::mat4& matrix)
{
  if (loc != -1)
    glUniformMatrix4fv(loc, 1, GL_FALSE, &matrix[0][0]);
}

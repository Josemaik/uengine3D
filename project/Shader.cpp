#include "Shader.h"
#include "Vertex.h"

#include <iostream>
using namespace std;

uint32_t Shader::getID() const
{
  return idProgram;
}

const char* Shader::getError() const
{
  return error_vertex_shader;
}

void Shader::use() const
{
  //Usar el programa
  glUseProgram(idProgram);
  //Anadir shader al programa
  glAttachShader(getID(), vertexShader);
  glAttachShader(getID(), fragmentShader);
  //Enlazar shaders
  glLinkProgram(getID());
  //Borrar shaders
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

void Shader::setupAttribs() const
{
  //Vertex Shader
  GLint location_vpos = glGetAttribLocation(idProgram, "vpos");
  if (location_vpos != -1)
  {
    //Activar escritura
    glEnableVertexAttribArray(location_vpos);
    //Especificar formato
    glVertexAttribPointer(location_vpos, 3, GL_FLOAT, false, sizeof(Vertex), reinterpret_cast<const
      void*>(offsetof(Vertex, position)));
  }
  //GLint location_vcolor = glGetAttribLocation(idProgram, "vcolor");
  //if (location_vcolor != -1)
  //{
  //  //Activar escritura
  //  glEnableVertexAttribArray(location_vcolor);
  //  //Especificar formato
  //  glVertexAttribPointer(location_vcolor, 3, GL_FLOAT, false, sizeof(Vertex), reinterpret_cast<const
  //    void*>(offsetof(Vertex, position)));
  //}
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
  glUniform1i(loc, val);
}

void Shader::setFloat(int loc, float val)
{
  glUniform1f(loc, val);
}

void Shader::setVec3(int loc, const glm::vec3& vec)
{
  glUniform3f(loc, vec.x, vec.y, vec.z);
}

void Shader::setVec4(int loc, const glm::vec4& vec)
{
  glUniform4f(loc, vec.x,vec.y,vec.z,vec.w);
}

void Shader::setMatrix(int loc, const glm::mat4& matrix)
{
  glUniformMatrix4fv(loc, 4, 0, &matrix[0][0]);
}

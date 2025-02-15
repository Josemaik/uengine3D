#include "Shader.h"
#include "Vertex.h"

#include <iostream>
//strings
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

static std::string readString(const std::string& filename) {
  std::ifstream istream(filename.c_str(), std::ios_base::binary);
  std::stringstream sstream;
  sstream << istream.rdbuf();
  return sstream.str();
}

//Shader::Shader(std::size_t id, const char* _vertex_path, const char* _fragment_path)
//{
//    m_id = id;
//    m_vertexPath = _vertex_path;
//    m_fragmentPath = _fragment_path;
//}

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

//Shader::Shader(std::size_t id, std::string vertexPath, std::string fragmentPath)
//{
//    m_id = id;
//    m_vertexPath = vertexPath;
//    m_fragmentPath = fragmentPath;
//}

bool Shader::load(const char* filePath)
{
    m_filepath = filePath;

    setup();

    return isLoaded();
}

void Shader::unload()
{
    glDeleteProgram(idProgram);
    m_isLoad = false;
    printf("Shader destruido\n");
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
  GLint location_vtex = glGetAttribLocation(idProgram, "vtex");

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
  if (location_vtex != -1)
  {
    glEnableVertexAttribArray(location_vtex);
    glVertexAttribPointer(location_vtex, 2, GL_FLOAT, false, sizeof(Vertex),
      reinterpret_cast<const void*>(offsetof(Vertex, textureCord)));
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

void Shader::setup()
{
    //Create Shaders
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    //Bindear
    std::string vertexShaderString = readString(std::string(m_vertexPath));
    const char* vertexShaderSource = vertexShaderString.c_str();
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);

    std::string fragmentShaderString = readString(std::string(m_fragmentPath));
    const char* fragmentShaderSource = fragmentShaderString.c_str();
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);

    //Compile
    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    int succes;
    char errorLog[512]{};
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &succes);
    if (!succes) {
        char errorLog[1024];
        glGetShaderInfoLog(vertexShader, sizeof(errorLog), nullptr, errorLog);
        glDeleteShader(vertexShader);
        std::cout << errorLog;
    }
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &succes);
    if (!succes) {
        char errorLog[1024];
        glGetShaderInfoLog(fragmentShader, sizeof(errorLog), nullptr, errorLog);
        glDeleteShader(fragmentShader);
        std::cout << errorLog;
    }
    //Create Program
    idProgram = glCreateProgram();
    //Link and attach shaders
    AttachandLink();

    m_isLoad = true;
}

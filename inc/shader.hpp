#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h>
#include <string>

GLuint create_shader_program(const std::string &vertexPath, const std::string &fragmentPath);

#endif
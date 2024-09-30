#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>

GLuint create_shader_program(const char *vertexPath, const char *fragmentPath);

#endif
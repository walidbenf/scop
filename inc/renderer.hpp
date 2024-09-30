#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <GL/glew.h>
#include "obj_parser.hpp"

void render_object(const Object3D &obj, GLuint shaderProgram);

#endif
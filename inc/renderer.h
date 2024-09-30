#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include "obj_parser.h"

void render_object(Object3D obj, GLuint shaderProgram);

#endif
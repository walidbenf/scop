#ifndef OBJ_PARSER_HPP
#define OBJ_PARSER_HPP

#include <vector>
#include <string>

struct Vec3 {
    float x, y, z;
};

struct Vec2 {
    float u, v;
};

struct Object3D {
    std::vector<Vec3> vertices;
    std::vector<Vec3> normals;
    std::vector<Vec2> texcoords;
};

Object3D load_obj(const std::string &filename);

#endif
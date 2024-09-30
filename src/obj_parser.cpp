#include "obj_parser.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

Object3D load_obj(const std::string &filename) {
    Object3D obj;

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;
        if (prefix == "v") {
            // Lire un sommet
            float x, y, z;
            iss >> x >> y >> z;
            obj.vertices.push_back({x, y, z});
        } else if (prefix == "vn") {
            // Lire une normale
            float x, y, z;
            iss >> x >> y >> z;
            obj.normals.push_back({x, y, z});
        } else if (prefix == "vt") {
            // Lire une coordonnée de texture
            float u, v;
            iss >> u >> v;
            obj.texcoords.push_back({u, v});
        }
        // à continuer
    }

    return obj;
}
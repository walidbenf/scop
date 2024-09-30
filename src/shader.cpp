#include "shader.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

GLuint create_shader_program(const std::string &vertexPath, const std::string &fragmentPath) {
   
	// Créer les shaders
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    // Lire le code source des shaders
    std::ifstream vertexFile(vertexPath);
    std::ifstream fragmentFile(fragmentPath);

    if (!vertexFile.is_open() || !fragmentFile.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir les fichiers de shaders");
    }

    std::stringstream vertexStream, fragmentStream;
    vertexStream << vertexFile.rdbuf();
    fragmentStream << fragmentFile.rdbuf();

    std::string vertexCode = vertexStream.str();
    std::string fragmentCode = fragmentStream.str();

    const char *vertexSource = vertexCode.c_str();
    const char *fragmentSource = fragmentCode.c_str();

    // Compiler le vertex shader
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    // Vérifier les erreurs de compilation
    GLint success;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        throw std::runtime_error("Erreur de compilation du vertex shader: " + std::string(infoLog));
    }

    // Compiler le fragment shader
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    // Vérifier les erreurs de compilation
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        throw std::runtime_error("Erreur de compilation du fragment shader: " + std::string(infoLog));
    }

    // Lier les shaders dans mon programme
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Vérifier les erreurs de liaison
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        throw std::runtime_error("Erreur de linkage du programme de shaders: " + std::string(infoLog));
    }

    // Supprimer les shaders compilés car ils sont maintenant liés dans le programme
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}
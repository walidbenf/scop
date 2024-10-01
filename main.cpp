#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "inc/obj_parser.hpp"
#include "inc/renderer.hpp"
#include "inc/shader.hpp"
#include <iostream>

int main() {
    if (!glfwInit()) {
        std::cerr << "Erreur lors de l'initialisation de GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "3D Viewer", NULL, NULL);
    if (!window) {
        std::cerr << "Erreur lors de la création de la fenêtre GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    // Chemin vers le fichier .obj
    std::string objFilePath = "simple_triangle.obj";
    std::cout << "Chargement du fichier .obj depuis : " << objFilePath << std::endl;

    // Charge et parse le fichier .obj
    Object3D obj;
    try {
        obj = load_obj(objFilePath);
    } catch (const std::runtime_error &e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    // Configure les shaders
    GLuint shaderProgram;
    try {
        shaderProgram = create_shader_program("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl");
    } catch (const std::runtime_error &e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    // Initialise les buffers
    init_buffers(obj);

    // Boucle principale
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Rendu de l'objet
        render_object(obj, shaderProgram);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
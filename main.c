#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "inc/obj_parser.h"
#include "inc/renderer.h"
#include "inc/shader.h"

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "3D Viewer", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    // Charge et parse le fichier .obj
    Object3D obj = load_obj("path/to/your/model.obj");

    // Configure les shaders
    GLuint shaderProgram = create_shader_program("vertex_shader.glsl", "fragment_shader.glsl");

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
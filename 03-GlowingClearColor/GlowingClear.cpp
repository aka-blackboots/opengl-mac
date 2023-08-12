#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <ctime>

using namespace std;

void render(double);

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Set GLFW version hints for OpenGL 4.1 core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(800, 600, "03 - Glowing Clear Color", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        cerr << "Failed to initialize GLEW" << endl;
        return -1;
    }

    // Get version and renderer information
    const GLubyte* renderer = glGetString(GL_RENDERER);
    const GLubyte* version = glGetString(GL_VERSION);
    cout << "Renderer: " << renderer << endl;
    cout << "OpenGL version supported: " << version << endl;

    // Main render loop
    while (!glfwWindowShouldClose(window)) {
        time_t currentTime = time(nullptr);
        render(currentTime);

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up and terminate
    glfwTerminate();
    return 0;
}

void render(double currentTime){
    // Set clear color
    const GLfloat color[] = { 
        (float)sin(currentTime) * 0.5f + 0.5f,
        (float)cos(currentTime) * 0.5f + 0.5f,
        0.0f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, color);
}

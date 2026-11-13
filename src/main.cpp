#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

int main() {
    if (glfwInit() == GLFW_FALSE) {
        return 1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "OMCshade", nullptr, nullptr);
    if (window == nullptr) {
        glfwTerminate();
        return 1;
    }

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

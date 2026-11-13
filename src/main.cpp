#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <cstdio>

namespace {
void glfwErrorCallback(int errorCode, const char* description) {
    std::fprintf(stderr, "GLFW error (%d): %s\n", errorCode, description);
}
}  // namespace

int main() {
    glfwSetErrorCallback(glfwErrorCallback);

    if (glfwInit() == GLFW_FALSE) {
        return 1;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(800, 600, "OMCshade", nullptr, nullptr);
    if (window == nullptr) {
        glfwTerminate();
        return 1;
    }

    while (!glfwWindowShouldClose(window)) {
        glfwWaitEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

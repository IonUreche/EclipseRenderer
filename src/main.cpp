#include <GLFW/glfw3.h>
#include <iostream>
#include "App/Window.h"

int main() {
    Window window;
    window.Run();
    return 0;

    //if (!glfwInit()) return -1;
    //std::cout<<"Hello World!"<<std::endl;
    //// Tell GLFW not to create an OpenGL context (since we'll use DX12/Vulkan)
    //glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
//
    //GLFWwindow* window = glfwCreateWindow(800, 600, "Eclipse Renderer", nullptr, nullptr);
//
    //while (!glfwWindowShouldClose(window)) {
    //    glfwPollEvents();
    //}
//
    //glfwDestroyWindow(window);
    //glfwTerminate();
    //return 0;
}
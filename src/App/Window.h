#ifndef ECLIPSERENDERER_WINDOW_H
#define ECLIPSERENDERER_WINDOW_H

//#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <memory>
#include <chrono>

namespace utils
{
    class Camera;
}

class Window
{
public:
    Window();
    ~Window();

    void Run();

    // Input
    void KeyCallback(int key, int scancode, int action, int mods);
    void MousePositionCallback(double xpos, double ypos);
    void MouseButtonCallback(int button, int action, int mods);

private:
    void InitWindow();
    void InitVulkan();
    void MainLoop();
    void Cleanup();

    void Update();

    GLFWwindow* m_glfwWindow;
    //std::unique_ptr<VulkanWindow> m_vulkanWindow;
    //std::unique_ptr<utils::Camera> m_camera;

    bool m_fullscreen = false;

    float m_time;
    std::chrono::steady_clock::time_point m_startTime;

    uint32_t m_moveDirMask;

    glm::vec2 m_lastMousePos;
    glm::vec2 m_leftClickPos;
    glm::vec2 m_rightClickPos;

    bool m_mouseLeftPressed = false;
    bool m_mouseRightPressed = false;
};

#endif //ECLIPSERENDERER_WINDOW_H
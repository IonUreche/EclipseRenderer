#include "Window.h"

#include "GLFW/glfw3native.h"

const uint32_t WIDTH = 1280;
const uint32_t HEIGHT = 768;

//======================================================================================
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window* wrapper = static_cast<Window*>(glfwGetWindowUserPointer(window));
	if (wrapper)
	{
		wrapper->KeyCallback(key, scancode, action, mods);
	}
}
//======================================================================================
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	Window* wrapper = static_cast<Window*>(glfwGetWindowUserPointer(window));
	if (wrapper)
	{
		wrapper->MousePositionCallback(xpos, ypos);
	}
}
//======================================================================================
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	Window* wrapper = static_cast<Window*>(glfwGetWindowUserPointer(window));
	if (wrapper)
	{
		wrapper->MouseButtonCallback(button, action, mods);
	}
}
//======================================================================================
Window::Window()
{
}
//======================================================================================
Window::~Window()
{
}
//======================================================================================
void Window::Run()
{
	InitWindow();
	InitVulkan();
	MainLoop();
	Cleanup();
}
//======================================================================================
void Window::InitWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	m_glfwWindow = glfwCreateWindow(WIDTH, HEIGHT, "Eclipse Renderer", m_fullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);

	glfwSetWindowUserPointer(m_glfwWindow, this);
	glfwSetKeyCallback(m_glfwWindow, key_callback);

	glfwSetInputMode(m_glfwWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(m_glfwWindow, cursor_position_callback);
	glfwSetMouseButtonCallback(m_glfwWindow, mouse_button_callback);
}
//======================================================================================
void Window::InitVulkan()
{
	//HWND hwnd = glfwGetWin32Window(m_glfwWindow);
	//m_vulkanWindow = std::unique_ptr<VulkanWindow>(new VulkanWindow(WIDTH, HEIGHT, reinterpret_cast<uint32_t>(hwnd)));
	//m_camera = std::unique_ptr<utils::Camera>(new utils::Camera(WIDTH, HEIGHT));
	//m_moveDirMask = 0;
	//m_startTime = std::chrono::high_resolution_clock::now();
}
//======================================================================================
void Window::MainLoop()
{
	while (!glfwWindowShouldClose(m_glfwWindow))
	{
		Update();
		glfwPollEvents();
	}
}
//======================================================================================
void Window::Cleanup()
{
	glfwDestroyWindow(m_glfwWindow);
	glfwTerminate();
}
//======================================================================================
void Window::Update()
{
	//auto currentTime = std::chrono::high_resolution_clock::now();
	//float deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - m_startTime).count();
	//m_startTime = currentTime;
//
	//m_time += deltaTime;
//
	//m_camera->SetMoveDirection(m_moveDirMask);
	//m_camera->Update(deltaTime);
	//m_vulkanWindow->SetView(m_camera->GetView());
	//m_vulkanWindow->SetProjection(m_camera->GetProjection());
	//m_vulkanWindow->DrawFrame();
}
//======================================================================================
void Window::KeyCallback(int key, int scancode, int action, int mods)
{
	//if (action == GLFW_PRESS)
	//{
	//	if (key == GLFW_KEY_W)
	//	{
	//		m_moveDirMask |= utils::MoveDirectionMasks::k_forward;
	//	}
	//	if (key == GLFW_KEY_S)
	//	{
	//		m_moveDirMask |= utils::MoveDirectionMasks::k_backwards;
	//	}
	//	if (key == GLFW_KEY_D)
	//	{
	//		m_moveDirMask |= utils::MoveDirectionMasks::k_right;
	//	}
	//	if (key == GLFW_KEY_A)
	//	{
	//		m_moveDirMask |= utils::MoveDirectionMasks::k_left;
	//	}
	//	if (key == GLFW_KEY_E)
	//	{
	//		m_moveDirMask |= utils::MoveDirectionMasks::k_up;
	//	}
	//	if (key == GLFW_KEY_Q)
	//	{
	//		m_moveDirMask |= utils::MoveDirectionMasks::k_down;
	//	}
	//	if (key == GLFW_KEY_LEFT_SHIFT)
	//	{
	//		//m_camera->SetFastSpeedMode(true);
	//	}
	//}
//
	//if (action == GLFW_RELEASE)
	//{
	//	if (key == GLFW_KEY_W)
	//	{
	//		m_moveDirMask &= ~utils::MoveDirectionMasks::k_forward;
	//	}
	//	if (key == GLFW_KEY_S)
	//	{
	//		m_moveDirMask &= ~utils::MoveDirectionMasks::k_backwards;
	//	}
	//	if (key == GLFW_KEY_D)
	//	{
	//		m_moveDirMask &= ~utils::MoveDirectionMasks::k_right;
	//	}
	//	if (key == GLFW_KEY_A)
	//	{
	//		m_moveDirMask &= ~utils::MoveDirectionMasks::k_left;
	//	}
	//	if (key == GLFW_KEY_E)
	//	{
	//		m_moveDirMask &= ~utils::MoveDirectionMasks::k_up;
	//	}
	//	if (key == GLFW_KEY_Q)
	//	{
	//		m_moveDirMask &= ~utils::MoveDirectionMasks::k_down;
	//	}
	//	if (key == GLFW_KEY_LEFT_SHIFT)
	//	{
	//		//m_camera->SetFastSpeedMode(false);
	//	}
	//}
}
//======================================================================================
void Window::MousePositionCallback(double xpos, double ypos)
{
	glm::vec2 currentMousePos(xpos, ypos);

	if (m_mouseLeftPressed)
	{
		glm::vec2 delta = currentMousePos - m_lastMousePos;
	
		float dXf = static_cast<float>(delta[0]) / static_cast<float>(WIDTH);
		float dYf = static_cast<float>(delta[1]) / static_cast<float>(HEIGHT);
	
		//m_camera->OnMouseMoveX(dXf);
		//m_camera->OnMouseMoveY(-dYf);
	}
	m_lastMousePos = currentMousePos;
}
//======================================================================================
void Window::MouseButtonCallback(int button, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		double xpos, ypos;
		glfwGetCursorPos(m_glfwWindow, &xpos, &ypos);
		glm::vec2 pos(xpos, ypos);
		if (button == GLFW_MOUSE_BUTTON_LEFT)
		{
			m_mouseLeftPressed = true;
			m_leftClickPos = pos;
		}
		if (button == GLFW_MOUSE_BUTTON_RIGHT)
		{
			m_mouseRightPressed = true;
			m_rightClickPos = pos;
		}
	}

	if (action == GLFW_RELEASE)
	{
		if (button == GLFW_MOUSE_BUTTON_LEFT)
		{
			m_mouseLeftPressed = false;
		}
		if (button == GLFW_MOUSE_BUTTON_RIGHT)
		{
			m_mouseRightPressed = false;
		}
	}
}
//======================================================================================
//======================================================================================
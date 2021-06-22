#include "Window.h"

#include <iostream>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

Window::Window(int width, int height) : width{ width }
{
	this->width = width;
	this->height = height;
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, "Investonomicon", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);
	glfwMaximizeWindow(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}
}

Window::~Window()
{
	glfwTerminate();
}

void Window::Draw() const
{
	glfwSwapBuffers(window);
}

bool Window::WindowShouldClose() const
{
	return glfwWindowShouldClose(window);
}

int Window::getWidth() const
{
	return width;
}

int Window::getHeight() const
{
	return height;
}

void Window::Resize(int width, int height)
{
	glViewport(0, 0, width, height);
}

GLFWwindow* Window::getRawWindow()
{
	return window;
}
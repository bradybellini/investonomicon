#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>


class Window {

public:
	Window(int width, int height);
	~Window();
	void Draw() const;
	bool WindowShouldClose() const;
	int getWidth() const;
	int getHeight() const;
	void Resize(int width, int height);
	GLFWwindow* getRawWindow();

private:
	int width, height;
	GLFWwindow* window;
};


#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "Window.h"

#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {

	Window* nwindow();

	glfwInit(); //

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); //
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); //
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //

	GLFWwindow* window = glfwCreateWindow(800, 600, "Hello Test", NULL, NULL); //

	glfwMakeContextCurrent(window); //

	gladLoadGL(); // maybe

	


	glViewport(0, 0, 800, 600);


	glfwSwapBuffers(window); //

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 460");

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.08f, 0.12f, 0.19f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin("New Window!");
		ImGui::Text("Hello new window");
		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
	
	ImGui_ImplGlfw_Shutdown();
	ImGui_ImplOpenGL3_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window); //
	glfwTerminate(); //

	return 0;
}
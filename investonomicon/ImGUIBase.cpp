#include "ImGUIBase.h"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

ImGuiBase::ImGuiBase()
{
	//this->window = new Window(800, 600);
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window->getRawWindow(), true);
	this->OpenGLVersion("#version 460");

}

ImGuiBase::~ImGuiBase()
{
	ImGui_ImplGlfw_Shutdown();
	ImGui_ImplOpenGL3_Shutdown();
	ImGui::DestroyContext();
}

void ImGuiBase::OpenGLVersion(const char* version)
{
	ImGui_ImplOpenGL3_Init(version);
}

void ImGuiBase::LoopBegin()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void ImGuiBase::LoopEnd()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	glfwSwapBuffers(this->window->getRawWindow());
	glfwPollEvents();
}

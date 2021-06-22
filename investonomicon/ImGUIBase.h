#pragma once

#include "Window.h"

class ImGuiBase {

public:
	ImGuiBase();
	~ImGuiBase();
	void OpenGLVersion(const char* version);
	void LoopBegin();
	void LoopEnd();
	Window* window;

private:
	

};


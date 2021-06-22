#pragma once

#include "ImGUIBase.h"

class Application {
public:
	Application();
	~Application();
	void Loop();

private:

	ImGuiBase* Base;

};
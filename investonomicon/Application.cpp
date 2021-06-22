#include "Application.h"

Application::Application()
{
	this->Base = new ImGuiBase;
}

Application::~Application()
{
}

void Application::Loop()
{
	while (Base->window->WindowShouldClose())
	{
		Base->LoopBegin();

		Base->LoopEnd();
	}

}

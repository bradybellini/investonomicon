#pragma once

#include <string>

class ImGUIWindowBase
{
public:
	ImGUIWindowBase(std::string windowname);
	~ImGUIWindowBase();
	virtual void Begin(std::string windowname);
	virtual void End();

private:

};
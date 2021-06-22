#include "ImGUIWindowBase.h"


ImGUIWindowBase::ImGUIWindowBase(std::string windowname)
{
	this->Begin(windowname);

	this->End();
}

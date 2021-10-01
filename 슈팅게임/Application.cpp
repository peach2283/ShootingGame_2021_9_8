#include "framework.h"

bool Application::isPlaying = true;

bool Application::getIsPlaying()
{
	return isPlaying;
}

void Application::quit()
{
	isPlaying = false;
}
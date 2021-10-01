#pragma once

class Application
{
private:
	static bool isPlaying;

public:
	static bool getIsPlaying();
	static void quit();
};
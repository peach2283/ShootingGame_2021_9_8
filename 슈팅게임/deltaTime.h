#pragma once

class Time
{
private:
	static float currTime;
	static float prevTime;	

public:

	static float timeScale;
	static float deltaTime;

	static void  init();
	static void  update();
};
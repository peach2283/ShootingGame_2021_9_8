#include "framework.h"

ReturningPlayer::ReturningPlayer(float px, float py) : Animation("","", true, px, py)
{
	this->speed = 150;
}

ReturningPlayer::~ReturningPlayer()
{}

void ReturningPlayer::start()
{
	for (int col = 0; col < 11; col++)
	{
		addImage("Asset/ÆÒÅÒ±ÍÈ¯.bmp", 64*col, 0, 62, 240, 0);
	}
}

void ReturningPlayer::update()
{
	float dist = speed * Time::deltaTime;
	translate(0, -dist);
}
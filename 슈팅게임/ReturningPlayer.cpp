#include "framework.h"

ReturningPlayer::ReturningPlayer(float px, float py) : Animation("","", true, px, py)
{}

ReturningPlayer::~ReturningPlayer()
{}

void ReturningPlayer::start()
{
	for (int col = 0; col < 11; col++)
	{
		addImage("Asset/ÆÒÅÒ±ÍÈ¯.bmp", 64*col, 0, 62, 240, 0);
	}
}
#include "framework.h"

Boss::Boss(float px, float py) :Sprite("", "", true, px, py)
{}

Boss::~Boss()
{}

void Boss::start()
{
	setImage("Asset/����.bmp", 0, 0, 493, 206);
}
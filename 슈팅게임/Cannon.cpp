#include "framework.h"

Cannon::Cannon(float px, float py) : Sprite("","",true, px, py)
{}

Cannon::~Cannon()
{}

void Cannon::start()
{
	setImage("Asset/º¸½º.bmp", 357, 262, 21, 22);
}
#include "framework.h"

Radar::Radar(float px, float py) : Sprite("","", true, px, py)
{}

Radar::~Radar()
{}

void Radar::start()
{
	setImage("Asset/����.bmp", 360, 245, 11, 9);
}
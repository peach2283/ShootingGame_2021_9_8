#include "framework.h"

EndingBG::EndingBG(float px, float py) : Sprite("","", true, px, py)
{}

EndingBG::~EndingBG()
{}

void EndingBG::start()
{
	setImage("Asset/�������.bmp");
}
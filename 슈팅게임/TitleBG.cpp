#include "framework.h"

TitleBG::TitleBG() : Sprite("","", true, 0,0)
{}

TitleBG::~TitleBG()
{}

void TitleBG::start()
{
	setImage("Asset/타이틀배경.bmp");
}
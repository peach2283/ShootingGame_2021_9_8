#include "framework.h"

HPBar::HPBar(float px, float py) : GameObject("","",true, px, py)
{
	this->fillAmount = 0;
}

HPBar::~HPBar()
{}

void HPBar::start()
{
	Bitmap::readBMP("Asset/UI/HPBG.bmp ", &BG);
	Bitmap::readBMP("Asset/UI/HPBar.bmp", &Bar);
}

void HPBar::draw()
{
	float px = getPx();
	float py = getPy();

	Bitmap::drawBMP(px + 1, py + 2, fillAmount,  &Bar);
	Bitmap::drawBMP(px,   py      , &BG);	
}

void HPBar::setFillAmount(float fillAmount)
{
	this->fillAmount = fillAmount;
}
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

	//텍스트 자식  UI 객체 추가하기//
	text=(Text *)addChildObject(new Text(78, 18), UI_LAYER);
	text->setText(L"100");
	text->setColor(255, 255, 255);
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

void HPBar::setText(wstring text)
{
	this->text->setText(text);
}
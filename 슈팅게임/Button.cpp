#include "framework.h"

Button::Button(float px, float py) : Sprite("","", true, px, py)
{}

Button::~Button()
{}

void Button::start()
{
	//버튼 이미지 로드하기//
	setImage("Asset/UI/item.bmp");
}

void Button::update()
{
	if (Input::getKeyDown("lbutton") == true)
	{
		cout << "마우스 왼쪽 버튼 눌림" << endl;
	}
}
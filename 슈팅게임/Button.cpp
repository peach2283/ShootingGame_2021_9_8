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
	//if(Input::getMouseButtonDown(0)==true)
	//{
	//	cout << "마우스 왼쪽버튼이 눌림" << endl;
	//}

	//마우스 좌표
	float mx = Input::mousePosition.x;
	float my = Input::mousePosition.y;

	//이미지 크기 구하기
	int width, height;
	getSize(width, height);

	//이미지 사각형 좌표
	float x0 = getPx();
	float y0 = getPy();

	float x1 = x0 + width;
	float y1 = y0 + height;
	
	if (x0 <= mx && mx <= x1 && y0 <= my && my <= y1)
	{
		cout << "마우스가..버튼 이미지 사각형 안에 있음" << endl;
	}

}